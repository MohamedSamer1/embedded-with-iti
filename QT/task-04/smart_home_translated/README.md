# 🏠 Smart Home Dashboard – Qt Quick Control Panel (with i18n)

![Platform](https://img.shields.io/badge/Platform-Cross--Platform-blue)
![Framework](https://img.shields.io/badge/Framework-Qt%20Quick-41CD52?logo=qt&logoColor=white)
![Language](https://img.shields.io/badge/Language-QML-orange)
![UI](https://img.shields.io/badge/UI-Qt%20Quick%20Controls%20Material-purple)
![i18n](https://img.shields.io/badge/i18n-English%20%2F%20Arabic-yellow)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

---

# 📖 Overview

**Smart Home Dashboard** is a modern smart home control interface built using **Qt Quick** and **QML**.

The project demonstrates how to create an interactive control panel for managing different smart home devices using Qt Quick Controls. It focuses on designing responsive user interfaces, handling user interaction, organizing layouts, navigating between multiple application pages, and — new in this version — **internationalization (i18n)** with runtime English/Arabic switching.

The application begins with a simple login screen. After successful authentication, the user is presented with a swipeable dashboard containing smart home controls including room temperature, lighting, fan speed, television controls, sound system, security camera monitoring, and application settings. The interface language can now be switched live from the Settings page.

This project is intended for learning QML UI development and does not include backend functionality or communication with real smart home devices.

---

# 🎯 Objectives

The objectives of this project are:

- Learn Qt Quick application development.
- Understand the structure of QML files.
- Build a modern dashboard interface.
- Practice using Qt Quick Layouts.
- Create interactive smart home controls.
- Navigate between pages using SwipeView.
- Use Material Design components.
- Improve UI styling and responsiveness.
- **Add internationalization (i18n) support with runtime language switching (English / Arabic).**
- **Mark all user-facing strings with `qsTr()` so they're translatable.**

---

# 🌐 What's New: Internationalization (i18n)

This version adds real i18n support on top of the original dashboard — the previous version only ever displayed English text with no translation mechanism at all.

Features:

- Every user-facing string wrapped in `qsTr()` (titles, labels, placeholders, control text) so it's picked up by Qt's translation tooling (`lupdate` / `.ts` files / `.qm` files).
- A `ComboBox` on the Settings page lets the user pick **English** or **Arabic**.
- Selecting a language calls into a C++ `languageManager` object:

```qml
ComboBox {
    model: ["English", "Arabic"]
    onCurrentTextChanged: {
        if (currentText === "Arabic")
            languageManager.changeLanguage("ar");
        else
            languageManager.changeLanguage("en");
    }
}
```

- The language change is applied at **runtime**, without restarting the app — `languageManager` is responsible for loading the corresponding Qt translation file and re-triggering re-evaluation of `qsTr()` bindings across the UI.

Screenshot:

![Language Switching](Assets/language_switch.png)

---

# ✨ Features

## 🔐 Login Screen

The application starts with a simple authentication interface.

Features:

- Username input
- Password input
- Login button
- Simple visibility toggle between the login screen and the dashboard (`login.visible` / `swipe.visible`)
- Automatic navigation after successful login

Screenshot:

![Login Screen](Assets/login.png)

---

# 🏠 Smart Home Dashboard

After logging in, users access the main dashboard.

The dashboard contains multiple smart home control cards displayed in a modern responsive layout, organized with `RowLayout`/`ColumnLayout` inside a `ScrollView`.

Features:

- Swipe navigation between Dashboard and Settings pages
- Scrollable content
- Responsive card-based layouts
- Material Design controls
- Dark interface (`#121212` background, `#1E1E1E` cards)

Screenshot:

![Dashboard](Assets/dashboard.png)

---

# 🌡️ Climate Control

Monitor and adjust room temperatures.

Features:

- Living Room temperature control (`Slider`, 16–30°C)
- Bedroom temperature control (`Slider`, 16–30°C)
- Live temperature readout above each slider, rounded to whole degrees
- Distinct accent color (`#2962FF`) for the primary temperature card

Screenshot:

![Climate Control](Assets/climate_control.png)

---

# 💡 Smart Device Controls

The dashboard provides controls for multiple smart home devices.

Features:

- Bedroom light switches with dependent brightness sliders (slider `enabled` state tied to the switch)
- Fan speed controls (Off / 1 / 2 / 3)
- Television controls (Off / 1–5, channel-style buttons)
- Sound system volume `Dial` with live percentage readout and power switch
- Dimmer control with dependent slider
- Security camera placeholder panel

Screenshot:

![Smart Devices](Assets/devices.png)

---

# ⚙️ Settings Page

The second `SwipeView` page contains application settings.

Features:

- Screen brightness slider with live numeric readout
- Notification volume slider with live numeric readout
- Theme selection (Dark / Light / System)
- **Language selection (English / Arabic) — wired to the live i18n system**
- Temperature unit selection (°C / °F)

Screenshot:

![Settings](Assets/settings.png)

---

# 🖥️ User Interface Design

The application uses a modern dashboard layout inspired by contemporary smart home systems.

The design includes:

- Material Design styling
- Dark theme
- Rounded dashboard cards
- Responsive layouts
- Swipe navigation
- Scrollable pages
- Organized spacing
- Interactive controls
- Fully translatable text via `qsTr()`

The application follows a simple workflow:

1. Login
2. Open Dashboard
3. Swipe between Dashboard and Settings pages
4. Control smart devices
5. Switch language from Settings, at any time, without restarting

---

# 🔄 What Changed From the Previous Version

| Before | Now |
|---|---|
| English-only, hardcoded strings | Every string wrapped in `qsTr()` for translation |
| No language switching mechanism | `ComboBox` in Settings switches language live |
| No backend hook for locale | `languageManager.changeLanguage("ar" / "en")` C++ integration |
| Static UI text | UI text is translation-ready for additional languages beyond English/Arabic |

---

# ⚙️ Application Flow

```text
Application Start
        |
        v
   Login Screen
        |
        v
 User Authentication
        |
        v
 Smart Home Dashboard
        |
        v
 Swipe Between Pages
        |
        v
 Control Smart Devices
        |
        v
 (Optional) Switch Language in Settings
        |
        v
 languageManager.changeLanguage()
        |
        v
 UI Text Updates via qsTr() Re-Evaluation
```

---

# 🛠️ Implementation

The complete front end is created using **QML**, with a C++ `languageManager` object handling locale switching.

## Window

Used as the main application container.

Responsible for:

- Window size
- Application title
- Main interface background color

---

## Rectangle

Used to create:

- Dashboard cards
- Login screen background
- Security camera panel
- Settings page background

Supports:

- Colors
- Borders
- Rounded corners
- Custom dimensions

---

## Text

Used for:

- Titles
- Device labels
- Temperature and volume values
- Application information

All user-facing instances wrapped in `qsTr()`.

---

## TextField

Used for:

- Username input
- Password input (`echoMode: "Password"`)

---

## Button

Used for:

- Login
- Fan speed controls
- TV channel controls

---

## Slider

Used for controlling:

- Temperature (both rooms)
- Light brightness (dependent on switch state)
- Dimmer level (dependent on switch state)
- Screen brightness
- Notification volume

---

## Switch

Used for enabling or disabling:

- Bedroom lights (both rooms)
- Dimmer
- Sound system power

---

## Dial

Used to control the sound system volume, with a live percentage readout below it.

---

## ComboBox

Used for selecting:

- Theme
- **Language — the key new i18n integration point**
- Temperature unit

---

## SwipeView

Used to navigate between the Dashboard and Settings pages.

---

## ScrollView

Provides scrolling support for both the Dashboard and Settings content.

---

# 📂 Project Structure

```text
SmartHome/
│
├── README.md
│
├── Assets/
│   ├── login.png
│   ├── dashboard.png
│   ├── climate_control.png
│   ├── devices.png
│   ├── settings.png
│   └── language_switch.png
│
├── translations/
│   ├── smarthome_en.ts
│   └── smarthome_ar.ts
│
├── CMakeLists.txt
├── main.cpp
├── languagemanager.h
├── languagemanager.cpp
├── Main.qml
└── Resources.qrc
```

---

# 📄 File Description

| File / Folder | Description |
|----------------|-------------|
| `Main.qml` | Main QML file containing the login screen, dashboard, and settings page. |
| `main.cpp` | C++ entry point that launches the Qt Quick application and registers `languageManager`. |
| `languagemanager.h` / `.cpp` | C++ class exposing `changeLanguage(QString locale)` to QML, responsible for loading the matching `.qm` translation file at runtime. |
| `CMakeLists.txt` | CMake configuration used to build the Qt project. |
| `Resources.qrc` | Qt resource file that stores application resources and compiled translations. |
| `translations/` | Qt Linguist `.ts` source files (and their compiled `.qm` counterparts) for English and Arabic. |
| `Assets/` | Contains screenshots used in the README documentation. |

---

# ▶️ Running the Application

To run the project:

1. Open **Qt Creator**.
2. Load the project.
3. Select the appropriate Qt Kit.
4. Build the application.
5. Run the project.

After launching:

- Enter a username.
- Enter a password.
- Click **Login**.
- Swipe between dashboard pages.
- Interact with the smart home controls.
- Open **Settings** and switch the **Language** dropdown to see the UI update live.

---

# 📚 QML Concepts Used

The project demonstrates:

- `Window`
  - Creating the main application window.

- `Rectangle`
  - Building dashboard cards and containers.

- `Text`
  - Displaying labels and values.

- `TextField`
  - Receiving user input.

- `Button`
  - Triggering user actions.

- `Slider`
  - Adjusting numeric values.

- `Switch`
  - Toggling smart devices.

- `Dial`
  - Controlling speaker volume.

- `ComboBox`
  - Selecting application options, including language.

- `ColumnLayout` / `RowLayout`
  - Organizing items vertically and horizontally.

- `ScrollView`
  - Creating scrollable pages.

- `SwipeView`
  - Navigating between multiple screens.

- `qsTr()`
  - Marking strings as translatable for Qt's internationalization system.

- Context Property (`languageManager`)
  - Exposing a C++ object to QML to trigger runtime locale changes.

- `Material Style`
  - Creating a modern application appearance.

---

# 🚀 Future Improvements

Possible future additions:

- User authentication backend
- Database integration
- MQTT communication
- IoT device connectivity
- Real-time sensor monitoring
- Camera streaming
- Push notifications
- Device scheduling
- Energy consumption monitoring
- Voice assistant integration
- Mobile responsive layout
- Smooth animations
- Additional languages beyond English/Arabic
- RTL layout mirroring for Arabic (`LayoutMirroring`)

---

# ✅ Result

Successfully extended the Smart Home Dashboard with full internationalization support using Qt Quick and QML.

The final application includes:

✅ Login interface  
✅ Smart Home dashboard  
✅ Swipe navigation  
✅ Temperature controls  
✅ Smart lighting controls  
✅ Fan controls  
✅ Television controls  
✅ Sound system controls  
✅ Security camera panel  
✅ Settings page  
✅ **English / Arabic language switching**  
✅ **Fully `qsTr()`-wrapped translatable strings**  
✅ Material Design interface  
✅ Responsive layouts  
✅ Qt Creator compatibility

---

# 📚 Technologies Used

- Qt Framework
- Qt Quick
- QML
- Qt Quick Controls
- Qt Quick Controls Material
- Qt Quick Layouts
- Qt Linguist (`.ts` / `.qm` translation files)
- Qt Creator
- CMake