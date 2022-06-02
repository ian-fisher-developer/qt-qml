cmake_minimum_required(VERSION 3.16)
project(adjustable_table LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(adjustable_table
    AdjustableTableModel.cpp AdjustableTableModel.h
    main.cpp
)

set_target_properties(adjustable_table PROPERTIES
    MACOSX_BUNDLE TRUE
)

target_link_libraries(adjustable_table PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

qt_add_qml_module(adjustable_table
    URI AdjustableTableModel
    VERSION 1.0
    QML_FILES main.qml CustomSlider.qml ColdHotGradient.qml HorizontalSliderHandle.png VerticalSliderHandle.png
    NO_RESOURCE_TARGET_PATH
)
