cmake_minimum_required(VERSION 3.16)
project(synchronized_controls LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(synchronized_controls
    AdjustableTableModel.cpp AdjustableTableModel.h
    main.cpp
)

set_target_properties(synchronized_controls PROPERTIES
    MACOSX_BUNDLE TRUE
)

target_link_libraries(synchronized_controls PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

qt_add_qml_module(synchronized_controls
    URI AdjustableTableModel
    VERSION 1.0
    QML_FILES main.qml AdjustableTable.qml
    NO_RESOURCE_TARGET_PATH
)
