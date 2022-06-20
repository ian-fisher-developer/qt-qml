project(transient_controls_app LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(transient_controls_app
    AdjustableTableModel.cpp AdjustableTableModel.h
    main.cpp
)

set_target_properties(transient_controls_app PROPERTIES
    MACOSX_BUNDLE TRUE
)

target_link_libraries(transient_controls_app PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

qt_add_qml_module(transient_controls_app
    URI AdjustableTableModel
    VERSION 1.0
    QML_FILES main.qml AdjustableTable.qml AdjustableTableNRowsControls.qml AdjustableTableNColsControls.qml
    NO_RESOURCE_TARGET_PATH
)
