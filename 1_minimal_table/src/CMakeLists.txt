project(minimal_table_app LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(minimal_table_app
    MinimalTableModel.cpp MinimalTableModel.h
    main.cpp
)

set_target_properties(minimal_table_app PROPERTIES
    MACOSX_BUNDLE TRUE
)

target_link_libraries(minimal_table_app PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

qt_add_qml_module(minimal_table_app
    URI MinimalTableModel
    VERSION 1.0
    QML_FILES main.qml
    NO_RESOURCE_TARGET_PATH
)
