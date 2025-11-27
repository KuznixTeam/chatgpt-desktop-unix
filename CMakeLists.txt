cmake_minimum_required(VERSION 3.16)

# ---------------------------------------------------------
# Project metadata
# ---------------------------------------------------------
project(chatgpt-desktop-unix
    VERSION 0.0.1         # Early 0.1.0 development build
    DESCRIPTION "Unofficial ChatGPT Desktop app for Linux (BSD & Unix soon). Built with Qt6."
    LANGUAGES CXX
)

# ---------------------------------------------------------
# Build settings
# ---------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable automatic MOC/UIC/RCC (Qt6 recommended)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ---------------------------------------------------------
# Qt 6 Dependencies
# ---------------------------------------------------------
find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    WebEngineWidgets
    WebEngineCore
)

# ---------------------------------------------------------
# Source files
# ---------------------------------------------------------
set(SOURCES
    src/main.cpp
    src/appwindow.cpp
    src/chatview.cpp
)

set(HEADERS
    src/appwindow.h
    src/chatview.h
)

set(RESOURCES
    resources/icons.qrc
)

# ---------------------------------------------------------
# Executable
# ---------------------------------------------------------
qt_add_executable(chatgpt-desktop-unix
    ${SOURCES}
    ${HEADERS}
    ${RESOURCES}
)

# ---------------------------------------------------------
# Linking
# ---------------------------------------------------------
target_link_libraries(chatgpt-desktop-unix
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::WebEngineWidgets
    Qt6::WebEngineCore
)

# ---------------------------------------------------------
# Install configuration (optional — distro packaging)
# ---------------------------------------------------------
install(TARGETS chatgpt-desktop-unix)

# Print build version info
message(STATUS "Building chatgpt-desktop-unix v${PROJECT_VERSION}")
