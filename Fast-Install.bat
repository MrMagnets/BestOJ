@echo off
setlocal enabledelayedexpansion
title BestOJ Installer

echo ========================================
echo    BestOJ Quick Installer v1.3
echo ========================================
echo.

rem --- detect compiler (gcc or g++) ---
set "CC="
where gcc >nul 2>nul && set "CC=gcc"
if not defined CC (
    where g++ >nul 2>nul && set "CC=g++"
)
if not defined CC (
    echo [ERROR] gcc/g++ not found in PATH.
    echo         Please install MinGW or MSYS2 and add it to PATH.
    goto fail
)

:menu
echo.
echo Please choose install method:
echo   [1] Auto install to gcc default include directory
echo   [2] Custom directory
echo   [0] Exit
echo.
set "choice="
set /p "choice=Enter your choice (0/1/2): "
if "%choice%"=="1" goto auto
if "%choice%"=="2" goto custom
if "%choice%"=="0" exit /b 0
echo [INFO] Invalid choice, please try again.
goto menu

:auto
echo.
echo [INFO] Detecting gcc default include directory...

rem write the include dir to a temp file, then read it back with set /p
rem (avoids for /f mangling the =include part of the option)
"%CC%" -print-file-name=include > "%TEMP%\bestoj_inc.txt" 2>nul
set "INC="
set /p INC=<"%TEMP%\bestoj_inc.txt"
del "%TEMP%\bestoj_inc.txt" >nul 2>nul

if not defined INC (
    echo [ERROR] Failed to locate gcc include directory.
    goto fail
)
echo [INFO] include dir: %INC%
set "DEST_INC=%INC%"

rem best-effort: derive a lib directory relative to the include dir
set "DEST_LIB="
set "C1=%DEST_INC%\..\lib"
if not defined DEST_LIB if exist "%C1%" set "DEST_LIB=%C1%"
set "C2=%DEST_INC%\..\..\lib"
if not defined DEST_LIB if exist "%C2%" set "DEST_LIB=%C2%"
set "C3=%DEST_INC%\..\..\..\lib"
if not defined DEST_LIB if exist "%C3%" set "DEST_LIB=%C3%"
set "C1="
set "C2="
set "C3="
if defined DEST_LIB (
    echo [INFO] lib dir: %DEST_LIB%
) else (
    echo [INFO] no lib directory found, library install will be skipped.
)
goto install

:custom
echo.
set "DEST_INC="
set /p "DEST_INC=Enter custom include directory: "
if "%DEST_INC%"=="" (
    echo [ERROR] Directory cannot be empty.
    echo.
    goto menu
)
echo.
set "DEST_LIB="
set /p "DEST_LIB=Enter custom lib directory (press Enter to skip): "
if "%DEST_LIB%"=="" set "DEST_LIB=%DEST_INC%"
goto install

:install
if not exist "%DEST_INC%" (
    echo [ERROR] include directory does not exist: %DEST_INC%
    goto fail
)
copy /y "BestOJ.h" "%DEST_INC%\BestOJ.h" >nul 2>nul
if errorlevel 1 (
    echo [WARN] Cannot write to %DEST_INC% - no write permission
    echo        Falling back to a local install:  include\
    set "LOCAL_INSTALL=1"
    set "DEST_INC=%~dp0include"
    if not exist "!DEST_INC!" mkdir "!DEST_INC!"
    set "DEST_LIB=!DEST_INC!"
    copy /y "BestOJ.h" "!DEST_INC!\BestOJ.h" >nul 2>nul
    if errorlevel 1 (
        echo [ERROR] Failed to copy BestOJ.h.
        goto fail
    )
)
echo [OK] BestOJ.h installed to %DEST_INC%
if defined LOCAL_INSTALL (
    echo.
    echo To compile with this local folder, use:
    echo   g++ -I"%~dp0include" main.cpp -L"%~dp0include" -lBestOJ
    echo.
) else (
    echo.
    echo Headers installed into the gcc search path, just use:
    echo   #include ^<BestOJ.h^>
    echo.
)

rem rebuild static library with the current compiler if possible
if not defined DEST_LIB goto done
if not exist "%DEST_LIB%" goto done
if not exist "BestOJ.cpp" (
    echo [INFO] BestOJ.cpp not found, skipping library install.
    goto done
)
echo [INFO] Rebuilding BestOJ.a with %CC% ...
%CC% -c BestOJ.cpp -o BestOJ_Install.o >nul 2>&1
if errorlevel 1 (
    echo [WARN] Compile failed, trying existing BestOJ.a ...
    if exist "BestOJ.a" (
        copy /y "BestOJ.a" "%DEST_LIB%\BestOJ.a" >nul
        if errorlevel 1 (
            echo [WARN] Failed to copy BestOJ.a.
        ) else (
            echo [OK] BestOJ.a installed to %DEST_LIB%
        )
    )
) else (
    if exist "BestOJ_Install.o" del /f "BestOJ_Install.o" >nul 2>nul
    ar rcs "BestOJ.a" BestOJ_Install.o >nul
    if errorlevel 1 (
        echo [WARN] ar failed, keeping existing BestOJ.a.
    ) else (
        copy /y "BestOJ.a" "%DEST_LIB%\BestOJ.a" >nul
        if errorlevel 1 (
            echo [WARN] Failed to copy BestOJ.a.
        ) else (
            echo [OK] BestOJ.a rebuilt and installed to %DEST_LIB%
        )
    )
)

:done
echo.
echo Install finished! Now you can use:  #include ^<BestOJ.h^>
pause
exit /b 0

:fail
echo.
echo Install aborted.
pause
exit /b 1