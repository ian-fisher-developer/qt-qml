cmake_minimum_required(VERSION 3.16)
project(minimal_table LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(minimal_table
    MinimalTableModel.cpp MinimalTableModel.h
    main.cpp
)

set_target_properties(minimal_table PROPERTIES
    MACOSX_BUNDLE TRUE
)

target_link_libraries(minimal_table PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

qt_add_qml_module(minimal_table
    URI MinimalTableModel
    VERSION 1.0
    QML_FILES main.qml
    NO_RESOURCE_TARGET_PATH
)
