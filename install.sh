#!/usr/bin/env bash
# ==========================================
#   BestOJ 快速安装脚本 (Linux / macOS)
# ==========================================
set -e

if ! command -v gcc >/dev/null 2>&1; then
    echo "[错误] 未找到 gcc，请先安装：sudo apt install gcc g++"
    exit 1
fi

menu() {
    echo ""
    echo "请选择安装方式："
    echo "  [1] 自动安装到 gcc 默认 include/lib 目录 (需要 sudo)"
    echo "  [2] 自定义安装目录"
    echo "  [0] 退出"
}

install_h() {
    local dir="$1"
    local libdir="$2"
    if [ ! -d "$dir" ]; then
        echo "[错误] include 目录不存在：$dir"
        exit 1
    fi
    cp -f BestOJ.h "$dir/BestOJ.h"
    echo "[成功] BestOJ.h 已安装到 $dir"

    # 用当前 g++ 重新编译并安装静态库，保证与当前平台兼容
    if command -v g++ >/dev/null 2>&1 && [ -f BestOJ.cpp ]; then
        echo "[信息] 正在用 g++ 重新编译 libBestOJ.a ..."
        g++ -c BestOJ.cpp -o BestOJ_Install.o
        ar rcs libBestOJ.a BestOJ_Install.o
        rm -f BestOJ_Install.o
        if [ -d "$libdir" ]; then
            cp -f libBestOJ.a "$libdir/libBestOJ.a"
            echo "[成功] libBestOJ.a 已安装到 $libdir"
        fi
    else
        echo "[提示] 未找到 g++ 或 BestOJ.cpp，跳过库文件安装。"
    fi
}

while true; do
    menu
    read -r -p "请输入选项(0/1/2)：" choice
    case "$choice" in
        1)
            inc="$(gcc -print-file-name=include)"
            inc="$(cd "$(dirname "$inc")" && pwd)/$(basename "$inc")"
            lbd="$(gcc -print-search-dirs 2>/dev/null \
                | sed -n 's/^libraries: =\([^:;]*\).*/\1/p' | tail -1)"
            echo "[信息] include 目录：$inc"
            echo "[信息] lib 目录    ：$lbd"
            if [ "$(id -u)" -ne 0 ]; then
                echo "[提示] 需要 sudo 权限才能写入系统目录。"
                sudo bash -c "cd '$PWD' && $(declare -f install_h); install_h '$inc' '$lbd'"
            else
                install_h "$inc" "$lbd"
            fi
            break
            ;;
        2)
            read -r -p "请输入自定义 include 目录：" dinc
            read -r -p "请输入自定义 lib 目录（回车跳过）：" dlbd
            [ -z "$dlbd" ] && dlbd="${dinc%/}"
            install_h "$dinc" "$dlbd"
            break
            ;;
        0)
            exit 0
            ;;
        *)
            echo "[提示] 输入无效，请重新选择。"
            ;;
    esac
done

echo ""
echo "安装完成！现在可用 #include <BestOJ.h> 引入库。"
exit 0