#include "BestOJ.h"
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

namespace BestOJ
{
    // ============================================
    // 1. 幂运算 a^b
    // ============================================
    long long power(long long a, long long b)
    {
        long long result = 1;
        for (long long i = 0; i < b; i++)
        {
            result *= a;
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
    // 4. 取模幂运算 (a^b) % mod
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
    // 5. 判断质数
    // ============================================
    bool isPrime(long long n)
    {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        
        long long limit = (long long)sqrt(n);
        for (long long i = 3; i <= limit; i += 2)
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
    // 8. 十进制 → 任意进制 (2~8)
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
    // 9. 任意进制 → 十进制 (2~8)
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
    // 13. 斐波那契数列第 n 项
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
}
