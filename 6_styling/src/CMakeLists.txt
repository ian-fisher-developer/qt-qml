cmake_minimum_required(VERSION 3.16)
project(styling LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(styling
    AdjustableTableModel.cpp AdjustableTableModel.h
    main.cpp
)

set_target_properties(styling PROPERTIES
    MACOSX_BUNDLE TRUE
)

target_link_libraries(styling PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

qt_add_qml_module(styling
    URI AdjustableTableModel
    VERSION 1.0
    QML_FILES main.qml AdjustableTable.qml AdjustableTableNRowsControls.qml AdjustableTableNColsControls.qml
    NO_RESOURCE_TARGET_PATH
)
