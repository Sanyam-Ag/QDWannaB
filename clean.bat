@echo off

if exist build (
    echo Deleting build directory...
    rmdir /s /q build
    echo Build directory removed.
) else (
    echo No build directory found.
)
