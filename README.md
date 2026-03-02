# QDWannaB

This is a small statistical engine project created with inspiration for multiple similar engines present publicly.

## Cmake Build Commands

```Inside tsengine:
> mkdir build
> cd build
> cmake ..
> cmake --build .
> cli\tsengine.exe
> tests\ts_tests.exe
```

## Dependency of Architecture

1. Core knows nothing about CLI
2. CLI -> Core
3. Engine is for pure mathematical interface called upon by main to execute mathematical formulas registered in command registry which is used in REPL loop.

## Statistical Operations supported

1. Mean
2. Variance
3. Standard Deviation
4. Min & Max
5. Count
6. Covariance
7. Correlation
