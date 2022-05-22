# Learning About Qt QML/Quick

My employer heavily uses Qt, with GUI elements from the mature QtWidgets module -- the best choice for rich desktop applications.

Many new projects (outside my employer) implement GUIs with the QtQML/QtQuick modules. They support more dynamic visuals, good for the desktop and especially suited to other environments such as browsers and mobile devices.

These are my personal investigations of QML, Quick, and CMake, learning by creating small, tested applications to run on the desktop and in a browser.

## Exercises

1. Minimal Table
    
   A minimal QML table view displays data from a small, fixed, C++ table model.
    
2. Adjustable Table

   A QML table view displays data from a C++ table model, with controls for the number of rows and columns.

## Configuration

QtQML and QtQuick are still evolving rapidly. Qt 6.2 introduced [many affordances][CO01]. These experiments use Qt 6.3.0, the latest at the time of writing. Each application is built via CMake, recommended by the latest QML/Quick documents for the new Qt/CMake build helpers.

Note that while the software is changing so quickly, the QML/Quick documents can be confusing, often including legacy advice, even under a Qt 6.3.0 banner. Try searching for CMake examples in the Qt/Examples/Qt-6.3.0 directory -- those concrete code implementations seem to be least ambiguous.

For now, I use QtCreator to configure, build, and run. That is fine for these personal learning exercises. A more production-like environment would require standalone build scripts and run scripts.

Each application builds in a Desktop configuration, and in a WebAssembly configuration (runs in a browser).

[CO01]: https://www.qt.io/blog/qml-modules-in-qt-6.2
        "QML Modules in Qt 6.2"

### WebAssembly

Some one-time setup is required for WebAssembly builds:

- Follow the [Emscripten, Getting Started][WA01] instructions -- emsdk 3.1.6 is recommended for Qt 6.3.0
- Use the Qt Maintenance tool to add the WebAssembly module to the Qt installation

That is all -- the tools for WebAssembly builds are in place.

Open one of the projects in QtCreator, create a WebAssembly build configuration, then build and run the project -- the application opens in a browser window.

The [Qt documents][WA02] have more details, including instructions to build and run from a command line.

[WA01]: https://emscripten.org/docs/getting_started/downloads.html
        "Getting started with the Emscripten SDK."
[WA02]: https://doc.qt.io/qt-6/wasm.html
        "Qt for WebAssembly"

