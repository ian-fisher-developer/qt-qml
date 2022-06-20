project(night_vision_style_app LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(night_vision_style_app
    main.cpp
    AdjustableTableModel.h
    AdjustableTableModel.cpp
)

set_target_properties(night_vision_style_app PROPERTIES
    MACOSX_BUNDLE TRUE
)

target_link_libraries(night_vision_style_app PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

qt_add_resources(night_vision_style_app "night_vision_style_app"
    PREFIX
        "/"
    FILES
        "qtquickcontrols2.conf"
)

qt_add_qml_module(night_vision_style_app
    URI AdjustableTableModel
    VERSION 1.0
    QML_FILES
        main.qml
        AdjustableTable.qml
        AdjustableTableNRowsControls.qml
        AdjustableTableNColsControls.qml
    NO_RESOURCE_TARGET_PATH
)
