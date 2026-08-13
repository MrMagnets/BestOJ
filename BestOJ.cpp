#include "BestOJ.h"
#include <cmath>
#include <algorithm>
#include <string>

namespace BestOJ
{
    // ============================================
    // 1. 快速幂 a^b
    // ============================================
    long long power(long long a, long long b)
    {
        if (b < 0) return 0;

        long long result = 1;
        while (b > 0)
        {
            if (b & 1) result *= a;
            a *= a;
            b >>= 1;
        }
        return result;
    }

    // ============================================
    // 2. 最大公约数（辗转相除法）
    // ============================================
    long long gcd(long long a, long long b)
    {
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0)
        {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // ============================================
    // 3. 最小公倍数
    // ============================================
    long long lcm(long long a, long long b)
    {
        if (a == 0 || b == 0) return 0;
        return a / gcd(a, b) * b;
    }

    // ============================================
    // 4. 取模快速幂 (a^b) % mod
    // ============================================
    long long pmod(long long a, long long b, long long mod)
    {
        if (mod == 1) return 0;

        long long result = 1;
        a %= mod;

        while (b > 0)
        {
            if (b & 1)
            {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return result;
    }

    // ============================================
    // 5. 判断素数
    // ============================================
    bool isPrime(long long n)
    {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for (long long i = 3; i <= n / i; i += 2)
        {
            if (n % i == 0) return false;
        }
        return true;
    }

    // ============================================
    // 6. 各位数字之和
    // ============================================
    long long numSum(long long n)
    {
        if (n < 0) n = -n;

        long long sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    // ============================================
    // 7. 数字反转
    // ============================================
    long long rvsNum(long long n)
    {
        if (n < 0) n = -n;

        long long reversed = 0;
        while (n > 0)
        {
            reversed = reversed * 10 + (n % 10);
            n /= 10;
        }
        return reversed;
    }

    // ============================================
    // 8. 十进制 转 base 进制 (2~8)
    //    注：base 越界时返回 -1，请保证 2<=base<=8
    // ============================================
    long long tBase(long long n, int base)
    {
        if (base < 2 || base > 8) return -1;
        if (n == 0) return 0;

        long long result = 0;
        long long multiplier = 1;
        bool isNegative = false;

        if (n < 0)
        {
            isNegative = true;
            n = -n;
        }

        while (n > 0)
        {
            int digit = n % base;
            result += digit * multiplier;
            multiplier *= 10;
            n /= base;
        }

        return isNegative ? -result : result;
    }

    // ============================================
    // 9. base 进制 转 十进制 (2~8)
    //    注：base 越界或含非法数字时返回 -1
    // ============================================
    long long fBase(long long n, int base)
    {
        if (base < 2 || base > 8) return -1;
        if (n == 0) return 0;

        long long result = 0;
        long long multiplier = 1;
        bool isNegative = false;

        if (n < 0)
        {
            isNegative = true;
            n = -n;
        }

        while (n > 0)
        {
            int digit = n % 10;
            if (digit >= base) return -1;

            result += digit * multiplier;
            multiplier *= base;
            n /= 10;
        }

        return isNegative ? -result : result;
    }

    // ============================================
    // 10. 排列数 P(n,m)
    // ============================================
    long long Permu(long long n, long long m)
    {
        if (m < 0 || m > n) return 0;

        long long result = 1;
        for (long long i = n; i > n - m; i--)
        {
            result *= i;
        }
        return result;
    }

    // ============================================
    // 11. 组合数 C(n,m)
    // ============================================
    long long Combi(long long n, long long m)
    {
        if (m < 0 || m > n) return 0;
        if (m > n - m) m = n - m;

        long long result = 1;
        for (long long i = 1; i <= m; i++)
        {
            result = result * (n - m + i) / i;
        }
        return result;
    }

    // ============================================
    // 12. 阶乘 n!
    // ============================================
    long long fact(long long n)
    {
        if (n < 0) return -1;
        if (n == 0 || n == 1) return 1;

        long long result = 1;
        for (long long i = 2; i <= n; i++)
        {
            result *= i;
        }
        return result;
    }

    // ============================================
    // 13. 斐波那契数列的第 n 项
    // ============================================
    long long fib(long long n)
    {
        if (n < 0) return -1;
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        long long a = 0, b = 1;
        for (long long i = 2; i <= n; i++)
        {
            long long temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }

    // ============================================
    // 14. 回文数判断
    // ============================================
    bool isPalind(long long n)
    {
        if (n < 0) return false;
        return n == rvsNum(n);
    }

    // ============================================
    // 15. 数组最大值
    // ============================================
    long long maxVal(long long a[], int n)
    {
        if (n <= 0) return 0;
        long long result = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] > result) result = a[i];
        }
        return result;
    }

    // ============================================
    // 16. 数组最小值
    // ============================================
    long long minVal(long long a[], int n)
    {
        if (n <= 0) return 0;
        long long result = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] < result) result = a[i];
        }
        return result;
    }

    // ============================================
    // 17. 数组求和
    // ============================================
    long long sumArr(long long a[], int n)
    {
        long long result = 0;
        for (int i = 0; i < n; i++)
        {
            result += a[i];
        }
        return result;
    }

    // ============================================
    // 18. 数组平均值
    // ============================================
    double avgArr(long long a[], int n)
    {
        if (n <= 0) return 0.0;
        return (double)sumArr(a, n) / n;
    }

    // ============================================
    // 19. 反转数组
    // ============================================
    void reverseArr(long long a[], int n)
    {
        for (int i = 0; i < n / 2; i++)
        {
            std::swap(a[i], a[n - i - 1]);
        }
    }

    // ============================================
    // 20. 统计元素出现次数
    // ============================================
    int countOccur(long long a[], int n, long long x)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x) count++;
        }
        return count;
    }

    // ============================================
    // 21. 转大写
    // ============================================
    std::string toUpper(const std::string& str)
    {
        std::string result = str;
        for (char& c : result)
        {
            if (c >= 'a' && c <= 'z') c -= 32;
        }
        return result;
    }

    // ============================================
    // 22. 转小写
    // ============================================
    std::string toLower(const std::string& str)
    {
        std::string result = str;
        for (char& c : result)
        {
            if (c >= 'A' && c <= 'Z') c += 32;
        }
        return result;
    }

    // ============================================
    // 23. 字符串长度
    // ============================================
    int strLen(const std::string& str)
    {
        return (int)str.length();
    }

    // ============================================
    // 24. 反转字符串
    // ============================================
    std::string strReverse(const std::string& str)
    {
        std::string result = str;
        int n = result.length();
        for (int i = 0; i < n / 2; i++)
        {
            std::swap(result[i], result[n - i - 1]);
        }
        return result;
    }

    // ============================================
    // 25. 字母异位词判断
    // ============================================
    bool isAnagram(const std::string& a, const std::string& b)
    {
        if (a.length() != b.length()) return false;

        std::string s1 = toLower(a);
        std::string s2 = toLower(b);

        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        return s1 == s2;
    }

    // ============================================
    // 26. 统计元音字母数
    // ============================================
    int countVowels(const std::string& str)
    {
        int count = 0;
        static const std::string vowels = "aeiouAEIOU";
        for (char c : str)
        {
            if (vowels.find(c) != std::string::npos) count++;
        }
        return count;
    }

    // ============================================
    // 27. 统计辅音字母数
    // ============================================
    int countConsonants(const std::string& str)
    {
        int count = 0;
        static const std::string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
        for (char c : str)
        {
            if (consonants.find(c) != std::string::npos) count++;
        }
        return count;
    }

    // ============================================
    // 28. 绝对值
    // ============================================
    long long absInt(long long n)
    {
        return n < 0 ? -n : n;
    }

    // ============================================
    // 29. 三数最大值
    // ============================================
    long long max3(long long a, long long b, long long c)
    {
        return std::max(std::max(a, b), c);
    }

    // ============================================
    // 30. 三数最小值
    // ============================================
    long long min3(long long a, long long b, long long c)
    {
        return std::min(std::min(a, b), c);
    }

    // ============================================
    // 31. 判断偶数
    // ============================================
    bool isEven(long long n)
    {
        return n % 2 == 0;
    }

    // ============================================
    // 32. 判断奇数
    // ============================================
    bool isOdd(long long n)
    {
        return n % 2 != 0;
    }

    // ============================================
    // 33. 平方
    // ============================================
    long long sqr(long long n)
    {
        return n * n;
    }

    // ============================================
    // 34. 判断是否为 2 的幂
    // ============================================
    bool isPowerOfTwo(long long n)
    {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }

    // ============================================
    // 35. 二进制中 1 的个数（负数按补码统计）
    // ============================================
    int countBits(long long n)
    {
        unsigned long long x = (unsigned long long)n;
        int count = 0;
        while (x > 0)
        {
            x &= x - 1;
            count++;
        }
        return count;
    }

    // ============================================
    // 36. 反转低 32 位比特
    // ============================================
    long long reverseBits(long long n)
    {
        unsigned long long x = (unsigned long long)n;
        unsigned long long result = 0;
        for (int i = 0; i < 32; i++)
        {
            result = (result << 1) | (x & 1);
            x >>= 1;
        }
        return (long long)result;
    }

    // ============================================
    // 37. 判断闰年
    // ============================================
    bool isLeapYear(int y)
    {
        if (y < 0) y = -y;
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    // ============================================
    // 38. 月份天数
    // ============================================
    int daysInMonth(int y, int m)
    {
        if (m < 1 || m > 12) return -1;

        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (m == 2 && isLeapYear(y)) return 29;
        return days[m - 1];
    }

    // ============================================
    // 39. 判断日期是否合法
    // ============================================
    bool isValidDate(int y, int m, int d)
    {
        if (m < 1 || m > 12) return false;
        if (d < 1) return false;

        int maxDay = daysInMonth(y, m);
        if (maxDay == -1) return false;

        return d <= maxDay;
    }
}
