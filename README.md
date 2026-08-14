# BestOJ - Best Optimized Journeys: C++ competitive programming snippets & function templates.
# 好竞旅 - 最好的竞赛之旅：C++ 环境一键配置及常用库

一个适用于算法竞赛（OI / ACM）的 C++ 常用函数库与安装程序，一键安装vscode（仅windows）并提供共 **54 个**常用函数，覆盖数组、字符串、数论、位运算、日期等类别。安装后可直接 `#include <BestOJ.h>` 使用。
（可以仅安装vscode）

## 特性
- 及其方便：小白也能上手
- 零依赖：仅依赖 C++ 标准库，不包含任何 `bits/stdc++.h` 万能头
- 不污染全局命名空间，所有函数均在 `BestOJ` 命名空间内
- 提供 Windows / Linux 一键安装脚本
- 跨平台自动使用当前 g++ 重新编译静态库，保证兼容

## 安装

### Windows
右键-以管理员身份运行BestOJ.bat。
（可选-安装BestOJ库）
双击运行 `Fast-Install.bat`，按提示选择：

- `[1]` 自动检测并安装到 gcc 默认 include/lib 目录
- `[2]` 自定义安装目录

也可以手动编译：

```bat
g++ -c BestOJ.cpp -o BestOJ.o
ar rcs BestOJ.a BestOJ.o
copy BestOJ.h <你的 include 目录>
copy BestOJ.a <你的 lib 目录>
```

### Linux / macOS

```bash
chmod +x install.sh
./install.sh
```

脚本会自动检测 gcc 目录（需 sudo）或让你自定义目录。

### 手动使用（免安装）

将 `BestOJ.h` 与本项目放在一起，编译时加入 `BestOJ.cpp`：

```bash
g++ main.cpp BestOJ.cpp -o main
```

## 使用方法
查看README_使用说明以了解如何使用vsocde。
查看本项目readme.md以了解如何使用BestOJ库。

```cpp
#include <BestOJ.h>
#include <iostream>

int main()
{
    std::cout << BestOJ::gcd(12, 18) << '\n';       // 6
    std::cout << BestOJ::pmod(2, 10, 1000) << '\n'; // 24
    std::cout << BestOJ::isPrime(7) << '\n';        // 1
    std::cout << BestOJ::toUpper("hello") << '\n';  // HELLO
    return 0;
}
```

如果不想反复写 `BestOJ::`，可以在源文件中添加：

```cpp
using namespace BestOJ;
```

## 函数列表
| 分类 | 函数 |
|------|------|
| 幂运算 | `power(a, b)` |
| 数论 | `gcd(a, b)`, `lcm(a, b)`, `isPrime(n)`, `isPrimeFast(n)` |
| 取模 | `pmod(a, b, mod)` |
| 进制转换 | `tBase(n, base)`, `fBase(n, base)` |
| 排列组合 | `Permu(n, m)`, `Combi(n, m)`, `fact(n)` |
| 数列 | `fib(n)` |
| 回文/数字 | `isPalind(n)`, `numSum(n)`, `rvsNum(n)` |
| 数组 | `maxVal()`, `minVal()`, `sumArr()`, `avgArr()`, `reverseArr()`, `countOccur()`, `isSorted()`, `findIndex()`, `isDescending()`, `allPositive()` |
| 字符串 | `toUpper()`, `toLower()`, `strLen()`, `strReverse()`, `isAnagram()`, `countVowels()`, `countConsonants()`, `isPalindromeStr()`, `countWords()`, `replaceChar()`, `removeSpaces()` |
| 数学 | `absInt()`, `max3()`, `min3()`, `isEven()`, `isOdd()`, `sqr()`, `cube()`, `isPerfectSquare()`, `isPerfectCube()` |
| 位运算 | `isPowerOfTwo()`, `countBits()`, `reverseBits()`, `isEvenBit()` |
| 日期 | `isLeapYear()`, `daysInMonth()`, `isValidDate()`, `dayOfWeek()`, `daysBetween()` |
## 目录结构

```
BestOJ.h         头文件（函数声明）
BestOJ.cpp       实现文件 
BestOJ.a
Fast-Install.bat  Windows 安装脚本
install.sh        Linux 安装脚本
```

## License

[MIT](LICENSE)
