# 🔗 QML ↔ C++ Integration Guide – Ways to Connect Frontend & Backend

![Platform](https://img.shields.io/badge/Platform-Cross--Platform-blue)
![Framework](https://img.shields.io/badge/Framework-Qt%20Quick-41CD52?logo=qt&logoColor=white)
![Language](https://img.shields.io/badge/Language-QML%20%2B%20C%2B%2B-orange)
![Topic](https://img.shields.io/badge/Topic-QML%2FC%2B%2B%20Integration-purple)
![Status](https://img.shields.io/badge/Status-Reference-brightgreen)

---

# 📖 Overview

Qt gives you several distinct ways to connect a **QML front end** to a **C++ backend**, and each one solves a slightly different problem. Picking the right one is less about "which is best" and more about "which fits this situation" — a single-instance app-wide object, a reusable type you'll create many of, or a piece of data a component absolutely cannot work without.

This guide walks through the main connection types used in Qt Quick applications, using the calculator project as a running example, and explains **what each one is, when to use it, and how it differs from the others**.

---

# 🎯 Objectives

The objectives of this reference are:

- Understand the different mechanisms for exposing C++ to QML.
- Learn the difference between a single shared object and a reusable QML type.
- Understand when a singleton is appropriate vs. when it's an anti-pattern.
- Learn what `required property` enforces and why it matters.
- Compare trade-offs so you can choose the right tool per situation.

---

# 🧩 Connection Types Covered

| Type | Best for |
|---|---|
| Context Property | One global object shared across all of QML (e.g. `backend`) |
| QML Registered Type (`QML_ELEMENT`) | A C++ class you want to instantiate *as a QML item*, possibly many times |
| Singleton (`QML_SINGLETON`) | One shared instance, but accessed like a proper QML type, not injected externally |
| Required Property | Data a component must receive to be valid — enforced at compile/load time |
| `Q_INVOKABLE` Function | Calling a C++ function directly from QML |
| Signals + `Connections` | Reacting in QML when something changes in C++ |
| `Q_PROPERTY` | Exposing a C++ member as a bindable QML property |

---

# 1️⃣ Context Properties

The simplest way to hand a C++ object to QML — used in the calculator project for `backend`.

## How it works

```cpp
Calc calculator;
engine.rootContext()->setContextProperty("backend", &calculator);
```

QML can now reference `backend` anywhere, globally, without importing anything:

```qml
Button {
    onClicked: backend.calculate(1, 2, "+")
}
```

## Characteristics

- Registered once, from C++, before the QML engine loads.
- Becomes a **global name** visible in every `.qml` file in that engine.
- There's exactly **one instance** — you didn't create a *type*, you injected an *object*.
- Cannot be instantiated inside QML (`Backend {}` doesn't work — there's no QML type, just a name pointing to an existing object).

## When to use it

- App-wide singletons like a settings manager, a network client, or (as here) a calculator engine.
- Quick prototyping — it's the fastest way to get *something* from C++ into QML.

## Downsides

- Not visible to static tools (QML linting/IDE autocomplete is weaker).
- Ties your QML to a specific C++ setup step — the QML file will error out at runtime if that context property was never registered, with no compile-time warning.

---

# 2️⃣ QML Registered Types (`QML_ELEMENT`)

Turns a C++ class into a real QML type that can be **imported and instantiated** like `Rectangle` or `Button`.

## How it works

```cpp
// calc.h
class Calc : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(double result READ result NOTIFY resultChanged)
public:
    Q_INVOKABLE void calculate(double a, double b, QString op);
    double result() const;
signals:
    void resultChanged();
private:
    double m_result = 0;
};
```

Then in QML, after importing the module:

```qml
import calculator

Calc {
    id: calc
}

Button {
    onClicked: calc.calculate(1, 2, "+")
}
```

## Characteristics

- Requires `QML_ELEMENT` (or `qmlRegisterType<Calc>(...)` the old, manual way) plus proper `CMakeLists.txt` module setup (`qt_add_qml_module`).
- You can create **as many instances as you want**, directly in QML, with `id`s like any other item.
- Fully visible to Qt Creator's autocomplete and QML tooling.

## When to use it

- Reusable data models — e.g. a `Contact` type you'll create one of per list entry.
- Anything you want QML developers to be able to instantiate declaratively, rather than have injected from C++.

## Downsides

- More setup than a context property (module registration, imports).
- Doesn't make sense for something that should only ever exist once (see Singleton below).

---

# 3️⃣ Singletons (`QML_SINGLETON`)

A middle ground: **one shared instance**, like a context property, but accessed as a proper **imported QML type**, not injected externally.

## How it works

```cpp
// calc.h
class Calc : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(double result READ result NOTIFY resultChanged)
public:
    Q_INVOKABLE void calculate(double a, double b, QString op);
    double result() const;
signals:
    void resultChanged();
private:
    double m_result = 0;
};
```

Then in QML:

```qml
import calculator

Button {
    onClicked: Calc.calculate(1, 2, "+")   // note: no id, called on the type name directly
}
```

## Characteristics

- No `setContextProperty` call needed in `main.cpp` at all — the engine creates and manages the single instance itself.
- Referenced by **type name**, not by an instance `id` — `Calc.calculate(...)`, similar to how you'd use `Math.random()` in JavaScript.
- Cannot be instantiated with `{}` — there's deliberately only ever one.

## When to use it

- Global state that's conceptually "one of," but you still want it to behave like a clean, importable QML type rather than something wired up from `main.cpp` — e.g. an app-wide `Settings` or `Logger`.

## Downsides

- Singletons (in any framework) can make testing harder and create hidden coupling between unrelated QML files that all silently depend on shared state.
- If you actually need multiple instances later, switching away from a singleton means changing every call site.

## Context Property vs Singleton — the real difference

Both give you "one shared object." The difference is **where the wiring lives**:
- **Context property**: wiring lives in `main.cpp` (`setContextProperty`). QML has no idea where `backend` came from.
- **Singleton**: wiring lives in the type declaration itself (`QML_SINGLETON`). QML imports it like any other type, and the engine handles creation.

---

# 4️⃣ Required Properties

A way to make a QML component **refuse to work** unless the parent gives it certain data — catches mistakes early instead of failing silently at runtime.

## How it works

```qml
// DigitButton.qml
Button {
    required property string digitValue
    text: digitValue
    onClicked: appendDigit(digitValue)
}
```

Using it *without* setting `digitValue` is a **compile-time/load-time error**, not a silent `undefined`:

```qml
DigitButton {}                     // ❌ Error: required property "digitValue" not set
DigitButton { digitValue: "7" }    // ✅ OK
```

## Characteristics

- Declared with the `required` keyword before `property`.
- Enforced when the component is instantiated — QML will refuse to load rather than let `digitValue` silently be `""`.
- Works for properties of any type, not just ones connected to C++ — but it's especially useful when a component wraps data that *must* come from a backend model (e.g. a delegate in a `Repeater` bound to a C++ model).

## When to use it

- Reusable components (like a `DigitButton` extracted from the calculator's `Repeater`) where forgetting to bind a property should be caught immediately, not discovered as a blank button in production.
- Delegates in views (`ListView`, `Repeater`) bound to backend model roles — makes it explicit which roles the delegate depends on.

## Downsides

- None, really — it's a safety net. The only "cost" is deciding which properties truly deserve to be mandatory vs. optional with a default.

---

# 5️⃣ `Q_INVOKABLE` Functions

Already used in the calculator (`calculate()`) — the way to let QML **call a C++ function directly**, as opposed to just reading a property.

## How it works

```cpp
Q_INVOKABLE void calculate(double a, double b, QString op);
```

```qml
onClicked: backend.calculate(12, 7, "*")
```

## Characteristics

- Works on **any** object exposed to QML — context property, registered type, or singleton — the mechanism is the same.
- Supports return values too: `Q_INVOKABLE double lastResult() const;` could be called as `var x = backend.lastResult()`.
- Different from a `Q_PROPERTY`: a property is for *state you read/bind to*, `Q_INVOKABLE` is for *actions you trigger*.

## When to use it

- Any time QML needs to **do something** in C++ — trigger a calculation, save a file, start a network request.

---

# 6️⃣ Signals + `Connections`

The reverse direction — C++ notifying QML that something changed, used in the calculator to catch `resultChanged()`.

## How it works

```cpp
signals:
    void resultChanged();
```

```qml
Connections {
    target: backend
    function onResultChanged() {
        displayText = backend.result.toString()
    }
}
```

## Characteristics

- The `on<SignalName>` naming convention is how QML auto-wires a handler to a specific C++ signal.
- `Connections { target: someObject }` lets you react to signals on an object that isn't the component you're currently writing — useful when the signal source (`backend`) is different from where you want to react (`Main.qml`'s state).
- If a property is declared with `Q_PROPERTY(... NOTIFY resultChanged)`, QML **bindings** (e.g. `text: backend.result`) update automatically without needing an explicit `Connections` block at all — `Connections` is only necessary when you need to run custom logic beyond a simple binding.

## When to use it

- Custom reactions to a change (like resetting multiple QML properties, as the calculator does), not just displaying a value.
- For simple "show this value" cases, prefer a direct property binding — it's less code and does the same job.

---

# 7️⃣ `Q_PROPERTY`

The mechanism that makes a C++ member **bindable** in QML, like `backend.result`.

## How it works

```cpp
Q_PROPERTY(double result READ result NOTIFY resultChanged)
```

```qml
Text {
    text: backend.result   // updates automatically whenever resultChanged() fires
}
```

## Characteristics

- `READ` specifies the getter function.
- `NOTIFY` specifies which signal fires when the value changes — this is what makes QML bindings **live**, instead of just reading the value once.
- Optionally supports `WRITE` for a setter, making the property settable from QML too.

## When to use it

- Any piece of backend state that QML should display or bind to reactively — the "nouns" of your backend, as opposed to `Q_INVOKABLE`'s "verbs."

---

# 🧭 Decision Guide

```text
Do you need QML to call an action in C++?
        |
        v
       Yes → Q_INVOKABLE

Do you need QML to react to a C++ value changing?
        |
        v
       Yes → Q_PROPERTY with NOTIFY (+ Connections if custom logic is needed)

Do you need exactly one shared backend object, wired from main.cpp?
        |
        v
       Yes → Context Property

Do you need exactly one shared backend object, but as a clean importable type?
        |
        v
       Yes → Singleton (QML_SINGLETON)

Do you need a reusable type QML can instantiate many times?
        |
        v
       Yes → QML_ELEMENT (registered type)

Do you need a component to refuse to work without certain data?
        |
        v
       Yes → required property
```

---

# 📂 Where These Appear in the Calculator Project

| File | Connection type used |
|---|---|
| `main.cpp` | Context Property (`setContextProperty("backend", &calculator)`) |
| `calc.h` | `Q_PROPERTY(result)`, `Q_INVOKABLE calculate()`, `resultChanged()` signal |
| `Main.qml` | `Connections { target: backend }` reacting to `resultChanged()` |

If the calculator were extended to register `Calc` as a proper QML type instead, `QML_ELEMENT` (or `QML_SINGLETON`, since there's only ever one calculator engine needed) would replace the `setContextProperty` call — and `Main.qml` would `import` the module and reference `Calc` directly instead of the injected `backend` name.

---

# 📚 Technologies Used

- Qt Framework
- Qt Quick / QML
- Qt QML type system (`QML_ELEMENT`, `QML_SINGLETON`)
- Qt Meta-Object System (`Q_OBJECT`, `Q_PROPERTY`, `Q_INVOKABLE`, signals)
- C++
- CMake (`qt_add_qml_module`)