# 🧮 Qt Quick Calculator – QML + C++ Backend

![Platform](https://img.shields.io/badge/Platform-Cross--Platform-blue)
![Framework](https://img.shields.io/badge/Framework-Qt%20Quick-41CD52?logo=qt&logoColor=white)
![Language](https://img.shields.io/badge/Language-QML%20%2B%20C%2B%2B-orange)
![UI](https://img.shields.io/badge/UI-Qt%20Quick%20Controls%20Material-purple)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

---

# 📖 Overview

**Qt Quick Calculator** is a simple, functional calculator app built using **Qt Quick**, **QML**, and a **C++ backend**.

The project demonstrates how to connect a QML front end to a C++ object exposed through `QQmlContext`, using `Q_INVOKABLE` functions and Qt's signal/slot system to pass data between the two layers. It focuses on QML state management, dynamic UI updates, and calling into C++ for the actual arithmetic.

The application presents a single dark-themed screen with a result display and a 4×4 button grid for digits, operators, clear, and equals. Numbers are typed on the QML side, sent to C++ for calculation, and the result is pushed back to the display through a Qt signal.

This project is intended for learning QML/C++ integration and does not include scientific functions, calculation history, or persistent storage.

---

# 🎯 Objectives

The objectives of this project are:

- Learn Qt Quick + C++ hybrid application development.
- Understand how to expose a C++ object to QML via `setContextProperty`.
- Practice using `Q_INVOKABLE` functions and Qt signals across the QML/C++ boundary.
- Build a working calculator state machine (first number, operator, second number).
- Use `GridLayout` and `Repeater` for a clean, reusable button layout.
- Apply Material Design styling with a dark theme.
- Handle edge cases like divide-by-zero, chained operations, and continuing from a previous result.

---

# ✨ Features

## 🖥️ Display

The top card shows the current expression as it's typed, and the full equation with its result once calculated.

Features:

- Live display of the number currently being entered
- Full expression view once an operator is pressed (e.g. `12 × 7`)
- Result shown alongside the equation after `=` (e.g. `12 × 7 = 84`)
- Auto-fit font sizing so longer expressions don't overflow
- Dark Material Design theme

---

## 🔢 Number Pad & Operators

A 4×4 grid built with `GridLayout` and a `Repeater`, covering digits `0–9`, a decimal point, and the four basic operators.

Features:

- Digit buttons append to the number currently being typed
- Decimal point guarded against multiple `.` in the same number
- Operator buttons (`+`, `-`, `×`, `/`) lock in the first number and switch entry to the second
- `=` triggers the calculation via the C++ backend
- `C` button clears all state and resets the display

---

## 🔁 Smart State Handling

The calculator tracks *which* number is currently being typed and whether the display is showing a fresh, untouched result.

Features:

- `enteringSecond` flag routes digits to the first or second number
- `freshResult` flag ensures typing a new digit after a result **replaces** it instead of appending to it
- Pressing an operator right after a result **chains** off that result (e.g. `84 +` continues from the previous answer)
- Guard clauses prevent invalid actions, like pressing an operator before any number is typed, or pressing `=` with missing operands

---

# ⚙️ Application Flow

```text
Application Start
        |
        v
   Type First Number
        |
        v
   Press Operator (+ - × /)
        |
        v
   Type Second Number
        |
        v
      Press "="
        |
        v
 QML calls backend.calculate()
        |
        v
   C++ computes result
        |
        v
 resultChanged() signal emitted
        |
        v
 QML updates display,
 resets state for next calculation
```

---

# 🛠️ Implementation

The application is split between a QML front end and a small C++ backend class.

## ApplicationWindow

The main container for the UI, holding the display card and the button grid.

Responsible for:

- Window size and title
- Hosting calculator state as QML properties (`firstNumber`, `secondNumber`, `operation`, `enteringSecond`, `freshResult`, `displayText`)
- Material dark theme

---

## Rectangle

Used to create:

- The display card background
- The full-window dark background

---

## Text

Used for:

- Showing `displayText`, which reflects the number being typed, the full expression, or the final equation with result

---

## Button

Used for:

- All 16 calculator keys (digits, operators, decimal point, equals)
- The `C` clear button

Each button's `onClicked` branches based on its own `text` value to decide whether it's a digit, an operator, or `=`.

---

## GridLayout + Repeater

Used to lay out the 16 main buttons in a 4×4 grid without repeating the same block of QML 16 times — a single `Repeater` iterates over a model array of button labels.

---

## Connections

Used to listen for the C++ `resultChanged()` signal and react to it in QML — updating `displayText`, storing the result as the new `firstNumber`, and resetting `operation`, `secondNumber`, `enteringSecond`, and `freshResult`.

---

## C++ Backend (`Calc` class)

Exposed to QML as the global `backend` object via:

```cpp
engine.rootContext()->setContextProperty("backend", &calculator);
```

Responsible for:

- `calculate(double a, double b, QString op)` — a `Q_INVOKABLE` function callable directly from QML
- Performing `+`, `-`, `*`, `/` on the two operands
- Returning `0` on divide-by-zero instead of crashing
- Emitting `resultChanged()` after every calculation so QML can react

---

# 📂 Project Structure

```text
Calculator/
│
├── README.md
│
├── Main.qml
├── main.cpp
├── calc.h
├── calc.cpp
└── CMakeLists.txt
```

---

# 📄 File Description

| File / Folder | Description |
|----------------|-------------|
| `Main.qml` | Main QML file containing the display, button grid, calculator state, and logic functions. |
| `main.cpp` | C++ entry point that launches the Qt Quick application and registers the `Calc` backend with QML. |
| `calc.h` | Header for the `Calc` class, declaring the `Q_INVOKABLE calculate()` function and `resultChanged()` signal. |
| `calc.cpp` | Implementation of the arithmetic logic (`+`, `-`, `*`, `/`) and divide-by-zero handling. |
| `CMakeLists.txt` | CMake configuration used to build the Qt project. |

---

# ▶️ Running the Application

To run the project:

1. Open **Qt Creator**.
2. Load the project.
3. Select the appropriate Qt Kit.
4. Build the application.
5. Run the project.

After launching:

- Type a number using the digit buttons.
- Press an operator (`+`, `-`, `×`, `/`).
- Type a second number.
- Press `=` to see the full equation and result.
- Press `C` to clear and start over.

---

# 📚 QML & C++ Concepts Used

The project demonstrates:

- `ApplicationWindow`
  - Creating the main application window and hosting state.

- `property` (QML)
  - Storing calculator state (`firstNumber`, `secondNumber`, `operation`, flags, `displayText`).

- `Rectangle`
  - Building the display card and background.

- `Text`
  - Displaying the live expression and result.

- `Button` + `onClicked`
  - Wiring user interaction to logic functions.

- `GridLayout` + `Repeater`
  - Laying out repeated UI elements without duplicating code.

- `Connections` + signal handlers (`onResultChanged`)
  - Reacting in QML to a signal emitted from C++.

- `Q_INVOKABLE`
  - Exposing a C++ member function so it can be called directly from QML.

- `Q_PROPERTY` / signals (C++)
  - Notifying QML when backend data changes.

- `setContextProperty`
  - Exposing a C++ object instance to the QML engine as a named context property (`backend`).

- `Material Style`
  - Creating a modern dark application appearance.

---

# 🚀 Future Improvements

Possible future additions:

- Show "Error" instead of `0` on divide-by-zero
- Keep a calculation history
- Support keyboard input in addition to on-screen buttons
- Add scientific functions (%, √, x², etc.)
- Add haptic/visual feedback on button press
- Persist last result between app launches
- Light/dark theme toggle
- Responsive layout for different screen sizes

---

# ✅ Result

Successfully created a working Qt Quick Calculator with a QML front end and a C++ arithmetic backend.

The final application includes:

✅ Digit entry with live display  
✅ All four basic operators  
✅ Full expression + result display  
✅ Chained calculations from a previous result  
✅ Replace-vs-append logic after a fresh result  
✅ Divide-by-zero safety  
✅ Clear button  
✅ Material Design dark interface  
✅ Qt Creator compatibility

---

# 📚 Technologies Used

- Qt Framework
- Qt Quick
- QML
- Qt Quick Controls
- Qt Quick Controls Material
- Qt Quick Layouts
- C++
- Qt Creator
- CMake