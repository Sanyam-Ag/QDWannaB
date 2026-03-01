@echo off
echo Creating build directory...

if not exist build (
    mkdir build
)

cd build

echo Running CMake configure...
cmake ..

if %errorlevel% neq 0 (
    echo CMake configure failed.
    exit /b %errorlevel%
)

echo Building project...
cmake --build .

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)

echo Build completed successfully.
