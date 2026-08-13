@echo off
chcp 65001 >nul 2>nul
setlocal enabledelayedexpansion

echo ========================================
echo    BestOJ 快速安装脚本 v1.1
echo ========================================
echo.

:menu
echo 请选择安装方式：
echo   [1] 自动安装到 gcc 默认 include/lib 目录
echo   [2] 自定义安装目录
echo   [0] 退出
echo.
set /p choice=请输入选项(0/1/2)：
if "%choice%"=="1" goto auto
if "%choice%"=="2" goto custom
if "%choice%"=="0" exit /b 0
echo [提示] 输入无效，请重新选择。
echo.
goto menu

:auto
echo.
echo [信息] 正在检测 gcc...
where gcc >nul 2>nul
if errorlevel 1 (
    echo [错误] 未找到 gcc，请确认已安装 gcc 并加入 PATH。
    echo        可改用自定义安装方式重试。
    pause
    exit /b 1
)

rem 获取 gcc 默认 include 目录（如 ...\lib\gcc\x86_64-w64-mingw32\8.1.0\include）
for /f "delims=" %%i in ('gcc -print-file-name=include') do set "INC=%%i"
if not exist "%INC%" (
    echo [错误] 无法定位 gcc include 目录：%INC%
    pause
    exit /b 1
)

rem 从 include 搜索路径中解析 lib 目录
set "LIB="
for /f "tokens=1,* delims==" %%i in ('gcc -print-search-dirs') do (
    if "%%i"=="libraries" for /f "delims=;" %%p in ("%%j") do set "LIB=%%p"
)
if "%LIB%"=="" (
    rem 回退：用 include 的上级 mingw lib 目录
    set "LIB=%INC%\..\..\..\lib"
)

set "DEST_INC=%INC%"
set "DEST_LIB=%LIB%"
goto install

:custom
echo.
set /p DEST_INC=请输入自定义 include 目录（用于安装 BestOJ.h）：
if "%DEST_INC%"=="" (
    echo [错误] 目录不能为空。
    echo.
    goto menu
)
rem 若不提供 lib 目录，则与 include 同目录
echo.
set /p DEST_LIB=请输入自定义 lib 目录（用于安装 BestOJ.a，可直接回车跳过）：
if "%DEST_LIB%"=="" set "DEST_LIB=%DEST_INC%"
goto install

:install
if not exist "%DEST_INC%" (
    echo [错误] include 目录不存在：%DEST_INC%
    pause
    exit /b 1
)
copy /y "BestOJ.h" "%DEST_INC%\BestOJ.h" >nul
if errorlevel 1 (
    echo [错误] 复制 BestOJ.h 失败。
    pause
    exit /b 1
)
echo [成功] BestOJ.h 已安装到 %DEST_INC%

rem 尝试用当前 g++ 重新编译并安装静态库，保证与当前环境兼容
if not exist "%DEST_LIB%" (
    echo [提示] lib 目录不存在，跳过库文件安装：%DEST_LIB%
    goto done
)
if not exist "BestOJ.cpp" (
    echo [提示] 未找到 BestOJ.cpp，跳过库文件安装。
    goto done
)
where g++ >nul 2>nul
if errorlevel 1 (
    echo [提示] 未找到 g++，跳过库文件安装。
    goto done
)
echo [信息] 正在用 g++ 重新编译 BestOJ.a ...
g++ -c BestOJ.cpp -o BestOJ_Install.o >nul 2>&1
if errorlevel 1 (
    echo [警告] 编译失败，尝试使用已有的 BestOJ.a。
    if exist "BestOJ.a" copy /y "BestOJ.a" "%DEST_LIB%\BestOJ.a" >nul && echo [成功] BestOJ.a 已安装到 %DEST_LIB%
) else (
    if exist "BestOJ.a" del /f "BestOJ.a" >nul 2>nul
    ar rcs "BestOJ.a" BestOJ_Install.o >nul
    copy /y "BestOJ.a" "%DEST_LIB%\BestOJ.a" >nul
    echo [成功] BestOJ.a 已重新编译并安装到 %DEST_LIB%
    del /f "BestOJ_Install.o" >nul 2>nul
)

:done
echo.
echo 安装完成！现在可用 #include ^<BestOJ.h^> 引入库。
pause
exit /b 0