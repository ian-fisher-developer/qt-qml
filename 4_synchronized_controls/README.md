# Synchronized Controls

Multiple, synchronized controls for the adjustable table.


## Description

The fourth exercise builds on the adjustable table exercise, adding more controls for the table dimensions.

GUIs often have multiple, synchronized controls for the same function, requiring common properties, rather than direct bindings between items.


## Tests

The same google-test suite from exercise two defines the variability of the adjustable table model dimensions.

```
[==========] Running 9 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 9 tests from AdjustableTableModel
[ RUN      ] AdjustableTableModel.hasMaximumDimensions
[       OK ] AdjustableTableModel.hasMaximumDimensions (0 ms)
[ RUN      ] AdjustableTableModel.hasDefaultDimensions
[       OK ] AdjustableTableModel.hasDefaultDimensions (0 ms)
[ RUN      ] AdjustableTableModel.enforcesMinimumNumberOfRows
[       OK ] AdjustableTableModel.enforcesMinimumNumberOfRows (0 ms)
[ RUN      ] AdjustableTableModel.enforcesMaximumNumberOfRows
[       OK ] AdjustableTableModel.enforcesMaximumNumberOfRows (0 ms)
[ RUN      ] AdjustableTableModel.enforcesMinimumNumberOfColumns
[       OK ] AdjustableTableModel.enforcesMinimumNumberOfColumns (0 ms)
[ RUN      ] AdjustableTableModel.enforcesMaximumNumberOfColumns
[       OK ] AdjustableTableModel.enforcesMaximumNumberOfColumns (0 ms)
[ RUN      ] AdjustableTableModel.displaysHeaderRowNumbers
[       OK ] AdjustableTableModel.displaysHeaderRowNumbers (0 ms)
[ RUN      ] AdjustableTableModel.displaysHeaderColumnLetters
[       OK ] AdjustableTableModel.displaysHeaderColumnLetters (0 ms)
[ RUN      ] AdjustableTableModel.displaysDataAsColumnHeaderPlusRowHeader
[       OK ] AdjustableTableModel.displaysDataAsColumnHeaderPlusRowHeader (0 ms)
[----------] 9 tests from AdjustableTableModel (0 ms total)

[----------] Global test environment tear-down
[==========] 9 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 9 tests.
```


## Desktop Application

![Running on the desktop 1](Desktop1.png)
![Running on the desktop 2](Desktop2.png)
