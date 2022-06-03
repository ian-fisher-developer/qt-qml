cmake_minimum_required(VERSION 3.16)
project(custom_slider LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(custom_slider
    AdjustableTableModel.cpp AdjustableTableModel.h
    main.cpp
)

set_target_properties(custom_slider PROPERTIES
    MACOSX_BUNDLE TRUE
)

target_link_libraries(custom_slider PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

qt_add_qml_module(custom_slider
    URI AdjustableTableModel
    VERSION 1.0
    QML_FILES main.qml CustomSlider.qml ColdHotGradient.qml HorizontalSliderHandle.png VerticalSliderHandle.png
    NO_RESOURCE_TARGET_PATH
)
