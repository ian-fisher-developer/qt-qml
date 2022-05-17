# 1_minimal_table

A simple QML table view displays data from a C++ table model.

## Motivation

The first project is simple, focusing on getting a working combination of Qt version and build system, for the Desktop and WebAssembly configurations.

The one code complication is the C++ data model for the QML view, demonstrating that data models used with QtWidgets views are easily re-used with QML views.