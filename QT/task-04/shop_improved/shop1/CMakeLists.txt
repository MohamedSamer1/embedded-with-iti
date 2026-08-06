cmake_minimum_required(VERSION 3.16)

project(shop1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Quick LinguistTools)

qt_standard_project_setup(
    REQUIRES 6.10
    I18N_SOURCE_LANGUAGE en
    I18N_TRANSLATED_LANGUAGES ar
)

# Content of downloaded design from Figma to Qt or similar
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

qt_add_executable(appshop1
    main.cpp
)
qt_add_qml_module(appshop1
    URI shop1
    QML_FILES
        Main.qml
    RESOURCES
        resources.qrc
)

qt_add_translations(appshop1
    TS_FILE_BASE qml
    TS_FILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/i18n"


)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appshop1 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appshop1
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appshop1
    PRIVATE Qt6::Quick
)

install(TARGETS appshop1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
