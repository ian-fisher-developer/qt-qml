project(custom_slider_app LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(custom_slider_app
    AdjustableTableModel.cpp AdjustableTableModel.h
    main.cpp
)

set_target_properties(custom_slider_app PROPERTIES
    MACOSX_BUNDLE TRUE
)

target_link_libraries(custom_slider_app PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

qt_add_qml_module(custom_slider_app
    URI AdjustableTableModel
    VERSION 1.0
    QML_FILES main.qml CustomSlider.qml ColdHotGradient.qml HorizontalSliderHandle.png VerticalSliderHandle.png
    NO_RESOURCE_TARGET_PATH
)
