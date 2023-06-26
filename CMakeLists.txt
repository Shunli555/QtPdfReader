cmake_minimum_required(VERSION 3.23)
project(QtPdfReader)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt/6.5.1/bin")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Pdf
        REQUIRED)

add_executable(QtPdfReader main.cpp src/MainApp.cpp src/MainApp.h)
target_link_libraries(QtPdfReader
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt6::Pdf)

