# Minimal Table

A simple QML table view displays data from a C++ table model.

## Description

The first application is most basic. It focuses on discovering the build details for a simple, tested, application that runs on the desktop and in a browser.

A C++ data model provides one code complication. It demonstrates that data models used with QtWidgets views may be re-used with QML/Quick views.

## Tests

A google-test suite defines the simple, fixed, C++ data model.

```
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from MinimalTableModel
[ RUN      ] MinimalTableModel.hasTwoRows
[       OK ] MinimalTableModel.hasTwoRows (0 ms)
[ RUN      ] MinimalTableModel.hasThreeColumns
[       OK ] MinimalTableModel.hasThreeColumns (0 ms)
[ RUN      ] MinimalTableModel.displays00StringInTopLeftCell
[       OK ] MinimalTableModel.displays00StringInTopLeftCell (0 ms)
[ RUN      ] MinimalTableModel.displays12StringInBottomRightCell
[       OK ] MinimalTableModel.displays12StringInBottomRightCell (0 ms)
[----------] 4 tests from MinimalTableModel (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 4 tests.
```

## Desktop Application

![Minimal table running on the desktop](Desktop.png "Desktop")

## Browser Application

The code complication means that this application does **not** run in [Qt Design Viewer][01], an otherwise convenient tool for previewing pure QML projects in a browser -- the C++ data model makes this a non-pure QML project.

[01]: https://qt-webassembly.io/designviewer/
      "Qt Design Viewer, powered by web assembly"

A full Emscripten/WebAssembly configuration build/run **does** work in a browser.

![Minimal table running in a browser](Browser.png "Browser")

