# 🚀 Smart Home Dashboard – Qt Quick Control Panel

![Platform](https://img.shields.io/badge/Platform-Cross--Platform-blue)
![Framework](https://img.shields.io/badge/Framework-Qt%20Quick-41CD52?logo=qt&logoColor=white)
![Language](https://img.shields.io/badge/Language-QML-orange)
![UI](https://img.shields.io/badge/UI-Qt%20Quick%20Controls-purple)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

---

# 📖 Overview

**Smart Home Dashboard** is a modern smart home control interface built using **Qt Quick** and **QML**.

The project demonstrates how to create an interactive control panel for managing different smart home devices using Qt Quick Controls. It focuses on designing responsive user interfaces, handling user interaction, organizing layouts, and navigating between multiple application pages.

The application begins with a simple login screen. After successful authentication, the user is presented with a swipeable dashboard containing smart home controls including room temperature, lighting, fan speed, television controls, sound system, security camera monitoring, and application settings.

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

---

# ✨ Features

## 🔐 Login Screen

The application starts with a simple authentication interface.

Features:

- Username input
- Password input
- Login button
- Dark Material Design theme
- Automatic navigation after successful login

Screenshot:

![Login Screen](Assets/login.png)

---

# 🏠 Smart Home Dashboard

After logging in, users access the main dashboard.

The dashboard contains multiple smart home control cards displayed in a modern responsive layout.

Features:

- Swipe navigation
- Scrollable content
- Responsive layouts
- Material Design controls
- Modern dark interface

Screenshot:

![Dashboard](Assets/dashboard.png)

---

# 🌡️ Climate Control

Monitor and adjust room temperatures.

Features:

- Living Room temperature control
- Bedroom temperature control
- Interactive temperature sliders
- Real-time temperature display

Screenshot:

![Climate Control](Assets/climate_control.png)

---

# 💡 Smart Device Controls

The dashboard provides controls for multiple smart home devices.

Features:

- Bedroom light switch
- Fan speed controls
- Television controls
- Sound system volume dial
- Power switches
- Dimmer control

Screenshot:

![Smart Devices](Assets/devices.png)

---

# ⚙️ Settings Page

The second SwipeView page contains application settings.

Features:

- Screen brightness slider
- Notification volume slider
- Theme selection
- Language selection
- Temperature unit selection

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

The application follows a simple workflow:

1. Login
2. Open Dashboard
3. Swipe between pages
4. Control smart devices

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
```

---

# 🛠️ Implementation

The complete application is created using **QML**.

The project uses several Qt Quick components.

## Window

Used as the main application container.

Responsible for:

- Window size
- Application title
- Main interface

---

## Rectangle

Used to create:

- Dashboard cards
- Background
- Login screen
- Security camera panel

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
- Temperature values
- Application information

---

## TextField

Used for:

- Username input
- Password input

---

## Button

Used for:

- Login
- Fan controls
- TV controls

---

## Slider

Used for controlling:

- Temperature
- Brightness
- Notification volume
- Light intensity

---

## Switch

Used for enabling or disabling:

- Lights
- Dimmer
- Sound system

---

## Dial

Used to control the sound system volume.

---

## ComboBox

Used for selecting:

- Theme
- Language
- Temperature unit

---

## SwipeView

Used to navigate between dashboard pages.

---

## ScrollView

Provides scrolling support for dashboard content.

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
│   └── settings.png
│
├── CMakeLists.txt
├── main.cpp
├── Main.qml
└── Resources.qrc
```

---

# 📄 File Description

| File / Folder | Description |
|----------------|-------------|
| `Main.qml` | Main QML file containing the login screen, dashboard, and settings page. |
| `main.cpp` | C++ entry point that launches the Qt Quick application. |
| `CMakeLists.txt` | CMake configuration used to build the Qt project. |
| `Resources.qrc` | Qt resource file that stores application resources. |
| `Assets/` | Contains screenshots used in the README documentation. |
| `login.png` | Screenshot of the login interface. |
| `dashboard.png` | Screenshot of the main Smart Home dashboard. |
| `climate_control.png` | Screenshot showing the climate control cards. |
| `devices.png` | Screenshot showing the smart device controls. |
| `settings.png` | Screenshot of the settings page. |

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
  - Selecting application options.

- `ColumnLayout`
  - Organizing items vertically.

- `RowLayout`
  - Organizing items horizontally.

- `ScrollView`
  - Creating scrollable pages.

- `SwipeView`
  - Navigating between multiple screens.

- `Anchors`
  - Positioning interface elements.

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

---

# ✅ Result

Successfully created a modern Smart Home Dashboard using Qt Quick and QML.

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
- Qt Creator
- CMake