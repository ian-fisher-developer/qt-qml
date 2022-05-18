# Learning About Qt QML/Quick

My employer heavily uses Qt, with GUI elements from the mature QtWidgets module. Most new projects (outside my employer) appear to implement GUIs with the newer QtQML/QtQuick modules, supporting more dynamic GUIs.

These are my personal investigations of QtQml and QtQuick.


## Applications

1. Minimal Table -- a simple QML table view displays data from a C++ table model


## Configuration

QML and Quick are still evolving rapidly. These experiments use Qt 6.3.0 -- the latest at the time of writing. Each project is built with CMake -- recommended by the latest QML/Quick documents.

Each project builds in a Desktop configuration, and in a WebAssembly configuration to run in a browser.

### WebAssembly

Some one-time setup is required for WebAssembly builds:

- Follow the [Emscripten, Getting Started][WA01] instructions -- emsdk 3.1.6 is recommended for Qt 6.3.0
- Use the Qt Maintenance tool to add the WebAssembly module to the Qt installation

That is all -- the tools for WebAssembly builds are in place.

Open one of the projects in QtCreator, create a WebAssembly build configuration, then build and run the project--the application opens in a browser window.

The [Qt documents][WA02] have more details, including command line options in place of building/running in QtCreator.

[WA01]: https://emscripten.org/docs/getting_started/downloads.html
        "Getting started with the Emscripten SDK."
[WA02]: https://doc.qt.io/qt-6/wasm.html
        "Qt for WebAssembly"

