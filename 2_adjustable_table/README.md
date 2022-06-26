# Adjustable Table

A QML table view displays data from a C++ table model, with controls for the number of rows and columns.


## Description

Builds on the minimal table exercise, giving the C++ table data model configurable dimensions. Two GUI sliders adjust the number of rows and columns.


## Implementation Highlights

In AdjustableTableModel.h

- Expose the model to QML with QML_ELEMENT and the Qt Properties System
- Sadly, the QML TableView does not natively support table headers

In main.qml

- Add the slider controls, arranging them with the table view in a grid
- Make the table model's nRows/nCols properties dependent on the corresponding slider value


## Tests

A google-test suite defines the variability of the adjustable table model dimensions.

```
[==========] Running 9 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 9 tests from AdjustableTableModelTest
[ RUN      ] AdjustableTableModelTest.hasMaximumDimensions
[       OK ] AdjustableTableModelTest.hasMaximumDimensions (0 ms)
[ RUN      ] AdjustableTableModelTest.hasDefaultDimensions
[       OK ] AdjustableTableModelTest.hasDefaultDimensions (0 ms)
[ RUN      ] AdjustableTableModelTest.enforcesMinimumNumberOfRows
[       OK ] AdjustableTableModelTest.enforcesMinimumNumberOfRows (0 ms)
[ RUN      ] AdjustableTableModelTest.enforcesMaximumNumberOfRows
[       OK ] AdjustableTableModelTest.enforcesMaximumNumberOfRows (0 ms)
[ RUN      ] AdjustableTableModelTest.enforcesMinimumNumberOfColumns
[       OK ] AdjustableTableModelTest.enforcesMinimumNumberOfColumns (0 ms)
[ RUN      ] AdjustableTableModelTest.enforcesMaximumNumberOfColumns
[       OK ] AdjustableTableModelTest.enforcesMaximumNumberOfColumns (0 ms)
[ RUN      ] AdjustableTableModelTest.displaysHeaderRowNumbers
[       OK ] AdjustableTableModelTest.displaysHeaderRowNumbers (0 ms)
[ RUN      ] AdjustableTableModelTest.displaysHeaderColumnLetters
[       OK ] AdjustableTableModelTest.displaysHeaderColumnLetters (0 ms)
[ RUN      ] AdjustableTableModelTest.displaysDataAsColumnHeaderPlusRowHeader
[       OK ] AdjustableTableModelTest.displaysDataAsColumnHeaderPlusRowHeader (0 ms)
[----------] 9 tests from AdjustableTableModelTest (0 ms total)

[----------] Global test environment tear-down
[==========] 9 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 9 tests.
```


## Desktop Application

![Running on the desktop 1](Desktop1.png)
![Running on the desktop 2](Desktop2.png)


## Browser Application

![Running in a browser1](Browser1.png)
![Running in a browser2](Browser2.png)
