@echo off
chcp 65001 >nul
setlocal
title BestOJ - 竞赛环境一键配置工具
cd /d "%~dp0"
color 0A

rem ============================================================
rem  BestOJ.bat  竞赛环境一键配置
rem  1. 自动下载最新版 VSCode 并提示安装
rem  2. 自动安装 MSYS2 / MinGW-w64 (GCC + GDB)，使用清华 TUNA 源
rem  3. 自动配置 VSCode C/C++ 插件、编译任务、调试器、IntelliSense
rem  参考教程: https://code.visualstudio.com/docs/cpp/config-mingw
rem  用法: 双击运行；或加参数 -dry 仅预览生成工作区（不下载不安装）
rem ============================================================

if /i "%~1"=="-dry" goto :dryrun

rem ---------- 检查管理员权限 ----------
net session >nul 2>&1
if %errorlevel%==0 goto :is_admin
echo.
echo [信息] 本工具需要管理员权限来安装 MSYS2 并配置系统 PATH。
echo [信息] 正在重新启动并请求管理员权限，请在弹窗中点击"是"。
echo.
powershell -NoProfile -Command "Start-Process -FilePath '%~f0' -Verb RunAs"
exit /b

:is_admin
set "TMPD=%TEMP%\BestOJ"
if not exist "%TMPD%" mkdir "%TMPD%"

echo.
echo  ==============================================================
echo    BestOJ  竞赛环境一键配置工具
echo    ----------------------------------------------------------
echo    [1/5] VSCode 最新版     自动下载 + 提示安装
echo    [2/5] MinGW-w64 GCC     清华 TUNA 镜像自动安装
echo    [3/5] C/C++ 插件        自动安装
echo    [3.5] 中文语言包        可选（安装前询问）
echo    [4/5] 竞赛工作区        自动生成编译/调试/智能提示配置
echo    [5/5] 环境测试          编译运行验证
echo    [推荐]安装BestOJ        自行安装
echo    参考教程: https://code.visualstudio.com/docs/cpp/config-mingw
echo  ==============================================================
echo.
echo [提示] 若弹出 SmartScreen 安全警告，请点击"更多信息"-"仍要运行"。
echo.

rem ============================================================
rem  步骤 1/5: VSCode 最新版
rem ============================================================
echo [步骤 1/5] 检查 Visual Studio Code ...
set "VSCODE_EXE="
if exist "%LocalAppData%\Programs\Microsoft VS Code\Code.exe" set "VSCODE_EXE=%LocalAppData%\Programs\Microsoft VS Code\Code.exe"
if exist "%ProgramFiles%\Microsoft VS Code\Code.exe" set "VSCODE_EXE=%ProgramFiles%\Microsoft VS Code\Code.exe"
if defined VSCODE_EXE goto :vscode_ok

echo [信息] 未检测到 VSCode，开始自动下载最新版 ...
echo [信息] 说明: 清华镜像源不提供 VSCode 软件包，因此这里使用微软官方 CDN，
echo        它始终返回最新稳定版（国内访问速度良好）。
echo        备选下载地址: https://mirrors.huaweicloud.com/vscode/
echo.
curl.exe -L --retry 3 --connect-timeout 20 -o "%TMPD%\VSCodeUserSetup-x64-latest.exe" "https://update.code.visualstudio.com/latest/win32-x64-user/stable"
if not exist "%TMPD%\VSCodeUserSetup-x64-latest.exe" goto :vscode_fail
for %%F in ("%TMPD%\VSCodeUserSetup-x64-latest.exe") do set "VSIZE=%%~zF"
if not defined VSIZE goto :vscode_fail
if %VSIZE% LSS 1000000 goto :vscode_fail
echo [OK] 下载完成，大小约 %VSIZE% 字节。
echo.
echo [提示] 请选择 VSCode 安装方式:
echo        1. 静默自动安装（推荐，装完自动继续）
echo        2. 手动安装（打开安装向导，请一路"下一步"）
echo.
choice /c 12 /n /m "  请输入 1 或 2: "
if errorlevel 2 goto :vscode_manual

echo [信息] 正在静默安装 VSCode，约 1-2 分钟，请稍候 ...
"%TMPD%\VSCodeUserSetup-x64-latest.exe" /VERYSILENT /NORESTART /MERGETASKS=!runcode,addcontextmenufiles,addcontextmenufolders,associatewithfiles,addtopath
goto :vscode_after

:vscode_manual
echo [信息] 正在打开安装向导。安装完成后本窗口会自动继续 ...
echo [提示] 安装时建议勾选"添加到 PATH"和"添加到右键菜单"。
start /wait "" "%TMPD%\VSCodeUserSetup-x64-latest.exe"

:vscode_after
if exist "%LocalAppData%\Programs\Microsoft VS Code\Code.exe" set "VSCODE_EXE=%LocalAppData%\Programs\Microsoft VS Code\Code.exe"
if exist "%ProgramFiles%\Microsoft VS Code\Code.exe" set "VSCODE_EXE=%ProgramFiles%\Microsoft VS Code\Code.exe"
if defined VSCODE_EXE goto :vscode_ok
goto :vscode_fail

:vscode_fail
echo.
echo [错误] VSCode 未能自动安装成功。
echo [提示] 请手动下载安装: https://code.visualstudio.com/download
echo        安装完成后重新运行本脚本即可自动继续。
pause
exit /b 1

:vscode_ok
echo [OK] VSCode: %VSCODE_EXE%
echo.

rem ============================================================
rem  步骤 2/5: MSYS2 / MinGW-w64 (GCC + GDB)，清华源
rem ============================================================
echo [步骤 2/5] 检查 MinGW-w64 编译器 (GCC) ...
if exist "C:\msys64\ucrt64\bin\g++.exe" goto :mingw_ok

echo [信息] 未检测到 GCC，开始安装 MSYS2 + MinGW-w64（清华 TUNA 源）...
echo [信息] 正在从清华源查询最新的 MSYS2 安装包 ...
powershell -NoProfile -ExecutionPolicy Bypass -Command "$d=Join-Path $env:TEMP 'BestOJ'; $h=(Invoke-WebRequest -UseBasicParsing 'https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/x86_64/' -TimeoutSec 30).Content; $v=([regex]::Matches($h,'msys2-x86_64-\d{8}\.exe')|ForEach-Object{$_.Value}|Sort-Object|Select-Object -Last 1); if($v){[System.IO.File]::WriteAllText((Join-Path $d 'msys2url.txt'),('https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/x86_64/'+$v))}"
set /p MSYS2_URL=<"%TMPD%\msys2url.txt" 2>nul
if not defined MSYS2_URL set "MSYS2_URL=https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/x86_64/msys2-x86_64-20260611.exe"
echo [信息] MSYS2 安装包: %MSYS2_URL%
echo [信息] 开始下载（约 100MB，清华源速度较快）...
curl.exe -L --retry 3 --connect-timeout 20 -o "%TMPD%\msys2-installer.exe" "%MSYS2_URL%"
if not exist "%TMPD%\msys2-installer.exe" goto :msys2_fail
for %%F in ("%TMPD%\msys2-installer.exe") do set "MSIZE=%%~zF"
if not defined MSIZE goto :msys2_fail
if %MSIZE% LSS 1000000 goto :msys2_fail
echo [OK] 下载完成，大小约 %MSIZE% 字节。
echo [信息] 正在静默安装 MSYS2 到 C:\msys64 ...
"%TMPD%\msys2-installer.exe" in --confirm-command "echo BestOJ-ok" --accept-messages --root C:/msys64
if not exist "C:\msys64\usr\bin\bash.exe" goto :msys2_fail

echo [信息] 配置清华源 pacman 软件仓库 ...
> "C:\msys64\etc\pacman.d\mirrorlist.msys" echo Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/msys/$arch
> "C:\msys64\etc\pacman.d\mirrorlist.mingw32" echo Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/i686
> "C:\msys64\etc\pacman.d\mirrorlist.mingw64" echo Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/x86_64
> "C:\msys64\etc\pacman.d\mirrorlist.ucrt64" echo Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/ucrt64

echo [信息] 正在通过清华源安装 GCC 工具链（教程命令，约 1-2GB，请耐心等待）...
C:\msys64\usr\bin\bash.exe -lc "pacman -Sy --noconfirm && pacman -S --needed --noconfirm base-devel mingw-w64-ucrt-x86_64-toolchain"
if not exist "C:\msys64\ucrt64\bin\g++.exe" goto :msys2_fail

echo [信息] 正在把 C:\msys64\ucrt64\bin 和 C:\msys64\usr\bin 加入系统 PATH ...
powershell -NoProfile -Command "$p=[Environment]::GetEnvironmentVariable('Path','Machine'); if($p -notlike '*msys64*'){[Environment]::SetEnvironmentVariable('Path',$p.TrimEnd(';')+';C:\msys64\usr\bin;C:\msys64\ucrt64\bin','Machine'); Write-Output 'PATH 已更新'} else {Write-Output 'PATH 已存在'}"
goto :mingw_ok

:msys2_fail
echo.
echo [错误] MSYS2 / MinGW-w64 安装失败。
echo [提示] 请手动安装:
echo        1. 从 https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/x86_64/
echo           下载最新版 msys2-x86_64-xxxxxx.exe 并安装到 C:\msys64
echo        2. 打开 MSYS2 终端，执行:
echo           pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
echo        3. 把 C:\msys64\ucrt64\bin 和 C:\msys64\usr\bin 加入系统 PATH
pause
exit /b 1

:mingw_ok
set "PATH=C:\msys64\usr\bin;C:\msys64\ucrt64\bin;%PATH%"
echo [OK] 编译器版本:
C:\msys64\ucrt64\bin\g++.exe --version
echo.

rem ============================================================
rem  步骤 3/5: 安装 C/C++ 扩展
rem ============================================================
echo [步骤 3/5] 安装 VSCode C/C++ 扩展 ...
set "CODE_CMD="
if exist "%LocalAppData%\Programs\Microsoft VS Code\bin\code.cmd" set "CODE_CMD=%LocalAppData%\Programs\Microsoft VS Code\bin\code.cmd"
if exist "%ProgramFiles%\Microsoft VS Code\bin\code.cmd" set "CODE_CMD=%ProgramFiles%\Microsoft VS Code\bin\code.cmd"
if not defined CODE_CMD goto :ext_skip

echo [信息] 下载 C/C++ 扩展（cpptools，约 110MB）...
curl.exe -L --retry 3 --connect-timeout 20 --compressed -o "%TMPD%\cpptools.vsix" "https://marketplace.visualstudio.com/_apis/public/gallery/publishers/ms-vscode/vsextensions/cpptools/latest/vspackage"
if not exist "%TMPD%\cpptools.vsix" goto :ext_market
for %%F in ("%TMPD%\cpptools.vsix") do set "ESIZE=%%~zF"
if not defined ESIZE goto :ext_market
if %ESIZE% LSS 1000000 goto :ext_market
echo [信息] 正在安装扩展，请稍候 ...
call "%CODE_CMD%" --install-extension "%TMPD%\cpptools.vsix" --force
goto :ext_ok

:ext_market
echo [信息] 直链下载失败，改从 VSCode 扩展商店安装 ...
call "%CODE_CMD%" --install-extension ms-vscode.cpptools
goto :ext_ok

:ext_skip
echo [提示] 未找到 VSCode 命令行工具，跳过扩展安装。
echo       可稍后在 VSCode 扩展商店搜索 "C/C++" 手动安装。

:ext_ok
echo [OK] C/C++ 扩展安装完成。
echo.
if not defined CODE_CMD goto :zh_skip

echo [提示] 是否安装简体中文语言包（安装后 VSCode 界面变为中文）?
echo        1. 安装（推荐）
echo        2. 跳过
echo.
choice /c 12 /n /m "  请输入 1 或 2: "
if errorlevel 2 goto :zh_skip

echo [信息] 正在下载简体中文语言包（约 0.6MB）...
curl.exe -L --retry 3 --connect-timeout 20 --compressed -o "%TMPD%\zh-hans.vsix" "https://marketplace.visualstudio.com/_apis/public/gallery/publishers/ms-ceintl/vsextensions/vscode-language-pack-zh-hans/latest/vspackage"
if not exist "%TMPD%\zh-hans.vsix" goto :zh_market
for %%F in ("%TMPD%\zh-hans.vsix") do set "ZSIZE=%%~zF"
if not defined ZSIZE goto :zh_market
if %ZSIZE% LSS 100000 goto :zh_market
echo [信息] 正在安装中文语言包 ...
call "%CODE_CMD%" --install-extension "%TMPD%\zh-hans.vsix" --force
goto :zh_done

:zh_market
echo [信息] 直链下载失败，改从 VSCode 扩展商店安装 ...
call "%CODE_CMD%" --install-extension ms-ceintl.vscode-language-pack-zh-hans
goto :zh_done

:zh_skip
echo [信息] 已跳过中文语言包安装。

:zh_done
echo [OK] 步骤 3 完成（C/C++ 扩展 + 可选中文语言包）。
echo.

rem ============================================================
rem  步骤 4/5: 生成竞赛工作区
rem ============================================================
echo [步骤 4/5] 生成竞赛工作区 ...
set "DESK=%USERPROFILE%\Desktop"
if not exist "%DESK%" set "DESK=%USERPROFILE%\OneDrive\Desktop"
if not exist "%DESK%" set "DESK=%USERPROFILE%"
set "WS=%DESK%\BestOJ_Workspace"
if not exist "%WS%" mkdir "%WS%"
if not exist "%WS%\.vscode" mkdir "%WS%\.vscode"
call :setup_workspace
echo [OK] 工作区已生成: %WS%
echo.

rem ============================================================
rem  步骤 5/5: 编译运行测试
rem ============================================================
echo [步骤 5/5] 编译运行测试 ...
cd /d "%WS%"
echo [信息] 正在编译 main.cpp ...
C:\msys64\ucrt64\bin\g++.exe -O2 -Wall main.cpp -o main.exe
if errorlevel 1 goto :compile_fail
for /f "delims=" %%o in ('echo 3 5^| main.exe') do set "OUT=%%o"
if "%OUT%"=="8" goto :test_ok
echo [提示] 测试输出为 [%OUT%]，预期为 8，请检查环境。
goto :step5_done

:test_ok
echo [OK] 编译运行测试通过: 输入 3 5，输出 8。
goto :step5_done

:compile_fail
echo [错误] 编译测试未通过，请检查上方错误信息。

:step5_done
echo.
echo  ==============================================================
echo    BestOJ 竞赛环境配置完成！
echo  ==============================================================
echo.
echo  工作区: %WS%
echo  - 编译器: MinGW-w64 GCC（清华 TUNA 源），路径 C:\msys64\ucrt64\bin
echo  - 调试器: GDB
echo  - VSCode 已安装 C/C++ 扩展（编译/调试/智能提示）和中文语言包（如已选择）
echo.
echo  [下一步操作提示]
echo   1. 本窗口即将自动打开 VSCode；若未打开，请手动打开文件夹 %WS%
echo   2. 首次打开若提示信任文件夹，请选择"是，我信任作者"
echo   3. 打开 main.cpp，按 Ctrl+Shift+B 编译并运行（输出在下方终端面板）
echo   4. 按 F5 调试；在行号左侧点击可设置断点
echo   5. 写新题目: 在本文件夹新建 .cpp 文件并粘贴代码，保持该文件为
echo      当前激活标签页，再按 Ctrl+Shift+B 或 F5 即可编译调试
echo.
echo  [其他说明]
echo   - 重新运行本脚本是安全的，会自动跳过已安装的组件
echo   - 安装包缓存在 %TMPD%，确认无误后可手动删除
echo   - 如需安装更多库，在 MSYS2 终端执行: pacman -S 包名（已配清华源）
echo   - 参考教程: https://code.visualstudio.com/docs/cpp/config-mingw
echo.
if defined VSCODE_EXE start "" "%VSCODE_EXE%" "%WS%"
echo 按任意键退出...
pause >nul
exit /b 0

rem ============================================================
rem  干跑模式: 仅生成工作区文件，不下载不安装（用于预览/测试）
rem ============================================================
:dryrun
set "WS=%TEMP%\BestOJ_DryRun"
if not exist "%WS%" mkdir "%WS%"
if not exist "%WS%\.vscode" mkdir "%WS%\.vscode"
echo [干跑模式] 仅生成工作区文件，不进行任何下载和安装 ...
call :setup_workspace
echo.
echo [干跑完成] 工作区: %WS%
echo            请用文本编辑器或 VSCode 打开查看生成的配置文件。
pause >nul
exit /b 0

rem ============================================================
rem  子程序: 生成工作区文件（main.cpp + .vscode 配置 + 说明）
rem ============================================================
:setup_workspace

> "%WS%\main.cpp" echo // BestOJ 竞赛模板: 读入两个整数 a 和 b，输出它们的和
>> "%WS%\main.cpp" echo // 使用方法: 在 VSCode 中打开本文件后按 Ctrl+Shift+B 编译运行，按 F5 调试
>> "%WS%\main.cpp" echo #include ^<bits/stdc++.h^>
>> "%WS%\main.cpp" echo using namespace std;
>> "%WS%\main.cpp" echo.
>> "%WS%\main.cpp" echo int main^(^) {
>> "%WS%\main.cpp" echo     ios::sync_with_stdio^(false^);
>> "%WS%\main.cpp" echo     cin.tie^(nullptr^);
>> "%WS%\main.cpp" echo.
>> "%WS%\main.cpp" echo     int a, b;
>> "%WS%\main.cpp" echo     while ^(cin ^>^> a ^>^> b^) {
>> "%WS%\main.cpp" echo         cout ^<^< a + b ^<^< '\n';
>> "%WS%\main.cpp" echo     }
>> "%WS%\main.cpp" echo     return 0;
>> "%WS%\main.cpp" echo }

> "%WS%\.vscode\tasks.json" echo {
>> "%WS%\.vscode\tasks.json" echo     "tasks": [
>> "%WS%\.vscode\tasks.json" echo         {
>> "%WS%\.vscode\tasks.json" echo             "type": "cppbuild",
>> "%WS%\.vscode\tasks.json" echo             "label": "C/C++: g++.exe build active file",
>> "%WS%\.vscode\tasks.json" echo             "command": "C:/msys64/ucrt64/bin/g++.exe",
>> "%WS%\.vscode\tasks.json" echo             "args": [
>> "%WS%\.vscode\tasks.json" echo                 "-fdiagnostics-color=always",
>> "%WS%\.vscode\tasks.json" echo                 "-g",
>> "%WS%\.vscode\tasks.json" echo                 "${file}",
>> "%WS%\.vscode\tasks.json" echo                 "-o",
>> "%WS%\.vscode\tasks.json" echo                 "${fileDirname}\\${fileBasenameNoExtension}.exe"
>> "%WS%\.vscode\tasks.json" echo             ],
>> "%WS%\.vscode\tasks.json" echo             "options": {
>> "%WS%\.vscode\tasks.json" echo                 "cwd": "${fileDirname}"
>> "%WS%\.vscode\tasks.json" echo             },
>> "%WS%\.vscode\tasks.json" echo             "problemMatcher": [
>> "%WS%\.vscode\tasks.json" echo                 "$gcc"
>> "%WS%\.vscode\tasks.json" echo             ],
>> "%WS%\.vscode\tasks.json" echo             "group": {
>> "%WS%\.vscode\tasks.json" echo                 "kind": "build",
>> "%WS%\.vscode\tasks.json" echo                 "isDefault": true
>> "%WS%\.vscode\tasks.json" echo             },
>> "%WS%\.vscode\tasks.json" echo             "detail": "Task generated by Debugger."
>> "%WS%\.vscode\tasks.json" echo         }
>> "%WS%\.vscode\tasks.json" echo     ],
>> "%WS%\.vscode\tasks.json" echo     "version": "2.0.0"
>> "%WS%\.vscode\tasks.json" echo }

> "%WS%\.vscode\launch.json" echo {
>> "%WS%\.vscode\launch.json" echo     "configurations": [
>> "%WS%\.vscode\launch.json" echo         {
>> "%WS%\.vscode\launch.json" echo             "name": "C/C++: g++.exe build and debug active file",
>> "%WS%\.vscode\launch.json" echo             "type": "cppdbg",
>> "%WS%\.vscode\launch.json" echo             "request": "launch",
>> "%WS%\.vscode\launch.json" echo             "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
>> "%WS%\.vscode\launch.json" echo             "args": [],
>> "%WS%\.vscode\launch.json" echo             "stopAtEntry": false,
>> "%WS%\.vscode\launch.json" echo             "cwd": "${fileDirname}",
>> "%WS%\.vscode\launch.json" echo             "environment": [],
>> "%WS%\.vscode\launch.json" echo             "externalConsole": false,
>> "%WS%\.vscode\launch.json" echo             "MIMode": "gdb",
>> "%WS%\.vscode\launch.json" echo             "miDebuggerPath": "C:/msys64/ucrt64/bin/gdb.exe",
>> "%WS%\.vscode\launch.json" echo             "setupCommands": [
>> "%WS%\.vscode\launch.json" echo                 {
>> "%WS%\.vscode\launch.json" echo                     "description": "Enable pretty-printing for gdb",
>> "%WS%\.vscode\launch.json" echo                     "text": "-enable-pretty-printing",
>> "%WS%\.vscode\launch.json" echo                     "ignoreFailures": true
>> "%WS%\.vscode\launch.json" echo                 },
>> "%WS%\.vscode\launch.json" echo                 {
>> "%WS%\.vscode\launch.json" echo                     "description": "Set Disassembly Flavor to Intel",
>> "%WS%\.vscode\launch.json" echo                     "text": "-gdb-set disassembly-flavor intel",
>> "%WS%\.vscode\launch.json" echo                     "ignoreFailures": true
>> "%WS%\.vscode\launch.json" echo                 }
>> "%WS%\.vscode\launch.json" echo             ],
>> "%WS%\.vscode\launch.json" echo             "preLaunchTask": "C/C++: g++.exe build active file"
>> "%WS%\.vscode\launch.json" echo         }
>> "%WS%\.vscode\launch.json" echo     ],
>> "%WS%\.vscode\launch.json" echo     "version": "2.0.0"
>> "%WS%\.vscode\launch.json" echo }

> "%WS%\.vscode\c_cpp_properties.json" echo {
>> "%WS%\.vscode\c_cpp_properties.json" echo     "configurations": [
>> "%WS%\.vscode\c_cpp_properties.json" echo         {
>> "%WS%\.vscode\c_cpp_properties.json" echo             "name": "Win32",
>> "%WS%\.vscode\c_cpp_properties.json" echo             "includePath": [
>> "%WS%\.vscode\c_cpp_properties.json" echo                 "${workspaceFolder}/**",
>> "%WS%\.vscode\c_cpp_properties.json" echo                 "C:/msys64/ucrt64/include/**"
>> "%WS%\.vscode\c_cpp_properties.json" echo             ],
>> "%WS%\.vscode\c_cpp_properties.json" echo             "defines": [
>> "%WS%\.vscode\c_cpp_properties.json" echo                 "_DEBUG",
>> "%WS%\.vscode\c_cpp_properties.json" echo                 "UNICODE",
>> "%WS%\.vscode\c_cpp_properties.json" echo                 "_UNICODE"
>> "%WS%\.vscode\c_cpp_properties.json" echo             ],
>> "%WS%\.vscode\c_cpp_properties.json" echo             "compilerPath": "C:/msys64/ucrt64/bin/g++.exe",
>> "%WS%\.vscode\c_cpp_properties.json" echo             "cStandard": "c17",
>> "%WS%\.vscode\c_cpp_properties.json" echo             "cppStandard": "c++17",
>> "%WS%\.vscode\c_cpp_properties.json" echo             "intelliSenseMode": "windows-gcc-x64"
>> "%WS%\.vscode\c_cpp_properties.json" echo         }
>> "%WS%\.vscode\c_cpp_properties.json" echo     ],
>> "%WS%\.vscode\c_cpp_properties.json" echo     "version": 4
>> "%WS%\.vscode\c_cpp_properties.json" echo }

> "%WS%\README_使用说明.txt" echo ==========================================
>> "%WS%\README_使用说明.txt" echo  BestOJ 竞赛工作区 使用说明
>> "%WS%\README_使用说明.txt" echo ==========================================
>> "%WS%\README_使用说明.txt" echo.
>> "%WS%\README_使用说明.txt" echo 一、如何开始
>> "%WS%\README_使用说明.txt" echo  1. 打开 VSCode 并打开本文件夹（信任文件夹选"是，我信任作者"）
>> "%WS%\README_使用说明.txt" echo  2. 打开 main.cpp，按 Ctrl+Shift+B 编译并运行
>> "%WS%\README_使用说明.txt" echo  3. 按 F5 调试，可在行号左侧点击设置断点
>> "%WS%\README_使用说明.txt" echo.
>> "%WS%\README_使用说明.txt" echo 二、写新题目
>> "%WS%\README_使用说明.txt" echo  1. 在本文件夹新建 .cpp 文件，粘贴题目代码
>> "%WS%\README_使用说明.txt" echo  2. 保持该文件为激活标签页，按 Ctrl+Shift+B 或 F5
>> "%WS%\README_使用说明.txt" echo  3. 编译产物 .exe 会生成在同名 .cpp 旁边
>> "%WS%\README_使用说明.txt" echo.
>> "%WS%\README_使用说明.txt" echo 三、常用快捷键
>> "%WS%\README_使用说明.txt" echo  - Ctrl+Shift+B: 编译并运行当前文件
>> "%WS%\README_使用说明.txt" echo  - F5: 编译并调试当前文件
>> "%WS%\README_使用说明.txt" echo  - main.cpp 中的模板可复制另存为 template.cpp 备用
>> "%WS%\README_使用说明.txt" echo.
>> "%WS%\README_使用说明.txt" echo 四、如何提交 OJ
>> "%WS%\README_使用说明.txt" echo  把题目 .cpp 的代码内容复制到 OJ 的代码框提交即可
>> "%WS%\README_使用说明.txt" echo  本机 VSCode 只是编辑器，不参与 OJ 提交
>> "%WS%\README_使用说明.txt" echo.
>> "%WS%\README_使用说明.txt" echo 五、环境信息
>> "%WS%\README_使用说明.txt" echo  - 编译器: MinGW-w64 GCC（MSYS2 ucrt64），来自清华 TUNA 镜像
>> "%WS%\README_使用说明.txt" echo  - 调试器: GDB
>> "%WS%\README_使用说明.txt" echo  - 编译命令: g++ -g 源文件 -o 输出文件名
>> "%WS%\README_使用说明.txt" echo  - 安装更多库: MSYS2 终端执行 pacman -S 包名
>> "%WS%\README_使用说明.txt" echo  - 教程: https://code.visualstudio.com/docs/cpp/config-mingw
>> "%WS%\README_使用说明.txt" echo ==========================================

goto :eof
