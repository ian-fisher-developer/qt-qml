# 1_minimal_table

A simple QML table view displays data from a C++ table model.

## Description

The first application is most basic. It focuses on building a simple, working application for Desktop and WebAssembly configurations.

The C++ data model provides a code complication. It demonstrates that data models used with QtWidgets views may be re-used with QML/Quick views.

The code complication is significant. This application does not run in [Qt Design Viewer][01], a convenient tool for previewing pure QML projects in a browser. The C++ data model makes this a non-pure QML project. Ignoring Qt Design Viewer, a full WebAssembly configuration build/run does indeed work in a browser.

[01]: https://qt-webassembly.io/designviewer/
      "Qt Design Viewer, powered by web assembly"

