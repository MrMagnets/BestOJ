# BestOJ - Best Optimized Journeys: C++ competitive programming snippets & function templates.
# 好竞旅 - 最好的竞赛之旅：C++ 环境一键配置及常用库
## 官方交流群（QQ）：1105319703
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

### 幂运算
| 函数 | 说明 |
|------|------|
| `power(a, b)` | 计算 a 的 b 次方（快速幂） |

### 数论 / 取模
| 函数 | 说明 |
|------|------|
| `gcd(a, b)` | 最大公约数（欧几里得） |
| `lcm(a, b)` | 最小公倍数 |
| `isPrime(n)` | 判断素数 |
| `isPrimeFast(n)` | 快速判断素数（6k±1 优化） |
| `pmod(a, b, mod)` | 快速幂取模 `(a^b) % mod` |
| `gcdExtended(a, b, x, y)` | 扩展欧几里得算法 |
| `modInverse(a, mod)` | 求模逆元 |

### 进制转换
| 函数 | 说明 |
|------|------|
| `tBase(n, base)` | 十进制转 base 进制（2~8） |
| `fBase(n, base)` | base 进制转十进制（2~8） |

### 排列组合
| 函数 | 说明 |
|------|------|
| `Permu(n, m)` | 排列数 P(n, m) |
| `Combi(n, m)` | 组合数 C(n, m) |
| `fact(n)` | 阶乘 n! |
| `nextPermutation(a, n)` | 求下一个排列 |

### 数列 / 数字
| 函数 | 说明 |
|------|------|
| `fib(n)` | 斐波那契数列第 n 项 |
| `isPalind(n)` | 回文数判断 |
| `numSum(n)` | 各位数字之和 |
| `rvsNum(n)` | 数字反转 |
| `isArmstrong(n)` | 判断阿姆斯特朗数 |

### 排序
| 函数 | 说明 |
|------|------|
| `quickSort(a, l, r)` | 快速排序（升序） |
| `mergeSort(a, l, r)` | 归并排序（升序） |

### 搜索
| 函数 | 说明 |
|------|------|
| `binarySearch(a, n, x)` | 二分查找（数组需升序） |

### 数组操作
| 函数 | 说明 |
|------|------|
| `maxVal(a, n)` | 求最大值 |
| `minVal(a, n)` | 求最小值 |
| `sumArr(a, n)` | 求和 |
| `avgArr(a, n)` | 求平均值 |
| `reverseArr(a, n)` | 反转数组 |
| `countOccur(a, n, x)` | 统计元素 x 出现次数 |
| `isSorted(a, n)` | 判断数组是否升序 |
| `isDescending(a, n)` | 判断数组是否降序 |
| `findIndex(a, n, x)` | 查找元素首次出现位置 |
| `maxSubarraySum(a, n)` | 最大子数组和（Kadane 算法） |
| `rotateArray(a, n, k)` | 循环右移 k 位 |
| `removeDuplicates(a, n)` | 原地去重（返回去重后长度） |

### 字符串操作
| 函数 | 说明 |
|------|------|
| `toUpper(str)` | 转大写 |
| `toLower(str)` | 转小写 |
| `strLen(str)` | 字符串长度 |
| `strReverse(str)` | 反转字符串 |
| `isAnagram(a, b)` | 字母异位词判断 |
| `countVowels(str)` | 统计元音字母数 |
| `countConsonants(str)` | 统计辅音字母数 |
| `isPalindromeStr(str)` | 判断字符串是否为回文 |
| `countWords(str)` | 统计单词数量 |
| `replaceChar(str, old, new)` | 替换字符串中所有指定字符 |
| `longestCommonPrefix(a, b)` | 求两个字符串的最长公共前缀 |
| `editDistance(a, b)` | 编辑距离（Levenshtein Distance） |

### 数学工具
| 函数 | 说明 |
|------|------|
| `absInt(n)` | 绝对值 |
| `max3(a, b, c)` | 三数最大值 |
| `min3(a, b, c)` | 三数最小值 |
| `isEven(n)` | 判断偶数 |
| `isOdd(n)` | 判断奇数 |
| `sqr(n)` | 平方 |
| `cube(n)` | 立方 |
| `isPerfectSquare(n)` | 判断完全平方数 |
| `isPerfectCube(n)` | 判断完全立方数 |

### 位运算
| 函数 | 说明 |
|------|------|
| `isPowerOfTwo(n)` | 是否为 2 的幂 |
| `isPowerOfFour(n)` | 是否为 4 的幂 |
| `countBits(n)` | 二进制中 1 的个数 |
| `reverseBits(n)` | 反转低 32 位比特 |
| `isEvenBit(n)` | 用位运算判断偶数 |
| `lowbit(n)` | 返回 n 的二进制最低位 1 的值 |

### 日期工具
| 函数 | 说明 |
|------|------|
| `isLeapYear(y)` | 判断闰年 |
| `daysInMonth(y, m)` | 某月天数 |
| `isValidDate(y, m, d)` | 日期合法性校验 |
| `dayOfWeek(y, m, d)` | 计算星期几（0=周日） |
| `daysBetween(y1,m1,d1, y2,m2,d2)` | 计算两个日期相差天数 |
| `age(y1,m1,d1, y2,m2,d2)` | 计算年龄（年数） |
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
