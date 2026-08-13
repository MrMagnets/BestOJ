# BestOJ

一个适用于算法竞赛（OI / ACM）的 C++ 常用函数库，共 **39 个**常用函数，覆盖数组、字符串、数论、位运算、日期等类别。安装后可直接 `#include <BestOJ.h>` 使用。

## 特性

- 零依赖：仅依赖 C++ 标准库，不包含任何 `bits/stdc++.h` 万能头
- 不污染全局命名空间，所有函数均在 `BestOJ` 命名空间内
- 提供 Windows / Linux 一键安装脚本
- 跨平台自动使用当前 g++ 重新编译静态库，保证兼容

## 安装

### Windows

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
| `power(a, b)` | 计算 a 的 b 次方 |

### 数论 / 取模
| 函数 | 说明 |
|------|------|
| `gcd(a, b)` | 最大公约数（欧几里得） |
| `lcm(a, b)` | 最小公倍数 |
| `isPrime(n)` | 判断素数 |
| `pmod(a, b, mod)` | 快速幂取模 `(a^b) % mod` |

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

### 数列 / 数字
| 函数 | 说明 |
|------|------|
| `fib(n)` | 斐波那契数列第 n 项 |
| `isPalind(n)` | 回文数判断 |
| `numSum(n)` | 各位数字之和 |
| `rvsNum(n)` | 数字反转 |

### 数组操作
| 函数 | 说明 |
|------|------|
| `maxVal(a, n)` | 求最大值 |
| `minVal(a, n)` | 求最小值 |
| `sumArr(a, n)` | 求和 |
| `avgArr(a, n)` | 求平均值 |
| `reverseArr(a, n)` | 反转数组 |
| `countOccur(a, n, x)` | 统计元素 x 出现次数 |

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

### 数学工具
| 函数 | 说明 |
|------|------|
| `absInt(n)` | 绝对值 |
| `max3(a, b, c)` | 三数最大值 |
| `min3(a, b, c)` | 三数最小值 |
| `isEven(n)` | 判断偶数 |
| `isOdd(n)` | 判断奇数 |
| `sqr(n)` | 平方 |

### 位运算
| 函数 | 说明 |
|------|------|
| `isPowerOfTwo(n)` | 是否为 2 的幂 |
| `countBits(n)` | 二进制中 1 的个数 |
| `reverseBits(n)` | 反转低 32 位比特 |

### 日期工具
| 函数 | 说明 |
|------|------|
| `isLeapYear(y)` | 判断闰年 |
| `daysInMonth(y, m)` | 某月天数 |
| `isValidDate(y, m, d)` | 日期合法性校验 |

## 目录结构

```
BestOJ.h         头文件（函数声明）
BestOJ.cpp       实现文件
Fast-Install.bat  Windows 安装脚本
install.sh        Linux 安装脚本
```

## License

[MIT](LICENSE)