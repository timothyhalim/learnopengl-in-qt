@echo off

REM Convenience wrapper for CMake commands

setlocal enableextensions enabledelayedexpansion

set PROJECT=Window
set BUILD=Release

set BUILD_DIR=build
set INSTALL_DIR=install

@REM Remove existing build folder
rmdir %BUILD_DIR% /S /Q
rmdir %INSTALL_DIR% /S /Q


cmake -B %BUILD_DIR% && cd %BUILD_DIR% && cmake --build . --target ALL_BUILD --config %BUILD%

@REM Move exe file
set EXE="%~dp0\build\%BUILD%\%PROJECT%.exe"

if not exist "%~dp0\install" mkdir ""%~dp0\install"

if exist %EXE% move %EXE% "%~dp0\install"

@REM Get QT Library
if %BUILD% == Release (
    set QT_NOT_CACHED=true 
    set QT_DEBUG_CONSOLE=false
)
"C:/Qt/5.15.2/msvc2019_64/bin/windeployqt.exe" "%~dp0\install\%PROJECT%.exe"

"%~dp0\install\%PROJECT%.exe"
