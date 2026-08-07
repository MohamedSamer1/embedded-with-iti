# 🛍️ ElectroShop – Qt Quick E-Commerce UI

![Platform](https://img.shields.io/badge/Platform-Cross--Platform-blue)
![Framework](https://img.shields.io/badge/Framework-Qt%20Quick-41CD52?logo=qt&logoColor=white)
![Language](https://img.shields.io/badge/Language-QML-orange)
![UI](https://img.shields.io/badge/UI-Qt%20Quick%20Controls%20Material-purple)
![i18n](https://img.shields.io/badge/i18n-English%20%2F%20Arabic-yellow)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

---

# 📖 Overview

**ElectroShop** is a modern electronics store interface built using **Qt Quick** and **QML**.

The project demonstrates how to build a proper storefront UI: a fixed header with search and cart summary, a scrollable grid of products with images and prices, an "Add to Cart" interaction with live feedback, and basic multi-language support through a C++-backed language manager.

This is a **rebuild** of an earlier shop UI project (a car-parts/Porsche-themed store) that was rough around the edges — inconsistent layout, no real visual hierarchy, and a UI that didn't feel like an actual shop. ElectroShop replaces it with a cleaner, denser, more realistic e-commerce layout: a real header bar, a proper `GridView` product catalog, and small UI-polish details (notification popups, dividers, hover-ready buttons) that the previous version was missing.

---

# 🎯 Objectives

The objectives of this project are:

- Rebuild the shop UI from scratch with a real e-commerce layout instead of a rough placeholder page.
- Practice structuring a fixed header with `RowLayout` alongside a scrollable content area.
- Use `GridView` with a `ListModel` to render a product catalog efficiently.
- Add interactive feedback (cart popup notification) instead of a static, non-reactive UI.
- Support runtime language switching through a C++ backend.
- Apply consistent spacing, color, and typography instead of default/unstyled controls.

---

# ✨ Features

## 🧭 Header Bar

A fixed top bar that stays visible while the product grid scrolls underneath it.

Features:

- Store title
- Search field with icon, expanding to fill available space
- Cart summary showing item total (icon + running price)
- Vertical dividers separating header sections
- Language selector (`ComboBox`) wired to a C++ `languageManager`

Screenshot:

![Header](Assets/header.png)

---

## 🛒 Product Catalog

The main content area, replacing the previous version's flat/plain listing with a proper grid layout.

Features:

- `GridView` with fixed cell sizing for a clean, aligned catalog
- Header section with a featured banner image and "Featured Items" title
- Product cards showing image, name, and price
- "Add to Cart" button per product with clear visual weight (dark filled button, white label)
- Scrollable and clipped content so the grid never bleeds outside its bounds

Screenshot:

![Product Grid](Assets/products.png)

---

## 🔔 Add-to-Cart Notification

A toast-style popup confirming the action, giving the UI a sense of feedback the previous version lacked.

Features:

- Non-modal `Popup` appearing near the top of the window
- Dynamic message showing which product was added
- Auto-dismiss after 1.5 seconds via `Timer`
- Rounded, bordered dark card style consistent with the rest of the UI

Screenshot:

![Cart Notification](Assets/notification.png)

---

## 🌐 Language Switching

Basic internationalization support driven from the header `ComboBox`.

Features:

- English / Arabic selection
- Calls into a C++ `languageManager` object to apply the change
- Structure ready to extend with `qsTr()` translations across the rest of the UI

---

# 🔄 What Changed From the Previous Version

The earlier project (Porsche/car-parts shop) had:

- No clear header/content separation
- Plain, unstyled product listing with little visual hierarchy
- No feedback when interacting with buttons
- Inconsistent spacing and default control styling

ElectroShop addresses each of these directly:

| Before | Now |
|---|---|
| No fixed header | Dedicated header `Rectangle` with `RowLayout`, search, cart, language switch |
| Plain list, no grid alignment | `GridView` with fixed `cellWidth`/`cellHeight` for a real catalog feel |
| No purchase feedback | `Popup` + `Timer` notification on "Add to Cart" |
| Flat, default-styled controls | Custom-styled search box, buttons, dividers, and card backgrounds |
| Single language only | Language `ComboBox` wired to a backend manager |

---

# ⚙️ Application Flow

```text
Application Start
        |
        v
   Header Loads (search, cart, language)
        |
        v
  Product Grid Loads (featured banner + items)
        |
        v
   User Searches / Browses Products
        |
        v
   User Clicks "Add to Cart"
        |
        v
  Notification Popup Appears
        |
        v
   Popup Auto-Dismisses After 1.5s
```

---

# 🛠️ Implementation

The application is built entirely in **QML**, with a small C++ hook for language switching.

## Window

Used as the main application container.

Responsible for:

- Window size and title
- Hosting the header and the product grid

---

## Rectangle

Used to create:

- The header bar background and border
- The search field container
- Section dividers
- Product card backgrounds

---

## RowLayout / Row / Column

Used to:

- Arrange header sections horizontally (title, search, cart, language)
- Stack cart label and price vertically
- Lay out product card contents (image, name, price, button)

---

## TextField

Used for:

- The product search input, styled with a transparent background and placeholder text

---

## ListModel + GridView

Used to:

- Store the product catalog as structured data (`name`, `price`, `image`)
- Render that data as a responsive, evenly-spaced grid via a `delegate`

---

## Image

Used for:

- The featured banner at the top of the product grid
- Individual product thumbnails inside each card

---

## Button

Used for:

- The "Add to Cart" action per product, with a custom `contentItem` and `background` for consistent dark styling

---

## Popup + Timer

Used to:

- Show a temporary confirmation message after adding an item to the cart
- Auto-close the popup without requiring user interaction

---

## ComboBox

Used for:

- Selecting the interface language, which calls into the C++ `languageManager` backend

---

# 📂 Project Structure

```text
ElectroShop/
│
├── README.md
│
├── Assets/
│   ├── header.png
│   ├── products.png
│   └── notification.png
│
├── images/
│   ├── laptop.jpeg
│   ├── iphone.png
│   ├── keyboard.png
│   ├── mouse.png
│   ├── monitor.png
│   ├── headphones.png
│   ├── speaker.png
│   ├── watch.png
│   ├── ps5.png
│   ├── controller.png
│   ├── ssd.jpg
│   ├── hub.png
│   ├── webcam.png
│   └── pic1.jpg
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
| `Main.qml` | Main QML file containing the header, product catalog, cart notification, and language selector. |
| `main.cpp` | C++ entry point that launches the Qt Quick application and registers the `languageManager` backend. |
| `CMakeLists.txt` | CMake configuration used to build the Qt project. |
| `Resources.qrc` | Qt resource file that stores product images and application resources. |
| `images/` | Product thumbnails and the featured banner image used in the catalog. |
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

- Browse the featured product grid.
- Use the search field to look for a product.
- Click **Add to Cart** on any product to see the confirmation popup.
- Switch languages from the header dropdown.

---

# 📚 QML Concepts Used

The project demonstrates:

- `Window`
  - Creating the main application window.

- `Rectangle`
  - Building the header bar, dividers, and product cards.

- `RowLayout` / `Row` / `Column`
  - Organizing header sections and product card content.

- `TextField`
  - Receiving search input.

- `ListModel`
  - Storing structured product data.

- `GridView`
  - Rendering the product catalog in a responsive grid.

- `Image`
  - Displaying the featured banner and product thumbnails.

- `Button`
  - Custom-styled "Add to Cart" action with `contentItem`/`background` overrides.

- `Popup` + `Timer`
  - Showing and auto-dismissing the cart notification.

- `ComboBox`
  - Selecting the application language.

- `Material Style`
  - Base styling foundation for controls.

---

# 🚀 Future Improvements

Possible future additions:

- Actual cart state (running total, item count, cart page)
- Product detail page on click
- Live search filtering of the grid
- Category filters / sorting
- Full translation coverage using `qsTr()` across every string
- Persist cart contents between sessions
- Product quantity selector
- Checkout flow

---

# ✅ Result

Successfully rebuilt the shop UI from a rough, unstyled prototype into a polished electronics storefront using Qt Quick and QML.

The final application includes:

✅ Fixed header with search, cart summary, and language switch  
✅ Scrollable, aligned product catalog via `GridView`  
✅ Featured banner section  
✅ Styled "Add to Cart" buttons  
✅ Toast-style cart notification with auto-dismiss  
✅ Basic multi-language support  
✅ Consistent visual styling throughout  
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