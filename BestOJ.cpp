#include "BestOJ.h"
#include <cmath>
#include <algorithm>
#include <string>

namespace BestOJ
{
    // ============================================
    // 1. å¿«é€Ÿå¹‚ a^b
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
    // 2. æœ€å¤§å…¬çº¦æ•°ï¼ˆè¾—è½¬ç›¸é™¤æ³•ï¼‰
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
    // 3. æœ€å°å…¬å€æ•°
    // ============================================
    long long lcm(long long a, long long b)
    {
        if (a == 0 || b == 0) return 0;
        return a / gcd(a, b) * b;
    }

    // ============================================
    // 4. å–æ¨¡å¿«é€Ÿå¹‚ (a^b) % mod
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
    // 5. åˆ¤æ–­ç´ æ•°
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
    // 6. å„ä½æ•°å­—ä¹‹å’Œ
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
    // 7. æ•°å­—åè½¬
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
    // 8. åè¿›åˆ¶ è½¬ base è¿›åˆ¶ (2~8)
    //    æ³¨ï¼šbase è¶Šç•Œæ—¶è¿”å› -1ï¼Œè¯·ä¿è¯ 2<=base<=8
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
    // 9. base è¿›åˆ¶ è½¬ åè¿›åˆ¶ (2~8)
    //    æ³¨ï¼šbase è¶Šç•Œæˆ–å«éæ³•æ•°å­—æ—¶è¿”å› -1
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
    // 10. æ’åˆ—æ•° P(n,m)
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
    // 11. ç»„åˆæ•° C(n,m)
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
    // 12. é˜¶ä¹˜ n!
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
    // 13. æ–æ³¢é‚£å¥‘æ•°åˆ—çš„ç¬¬ n é¡¹
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
    // 14. å›æ–‡æ•°åˆ¤æ–­
    // ============================================
    bool isPalind(long long n)
    {
        if (n < 0) return false;
        return n == rvsNum(n);
    }

    // ============================================
    // 15. æ•°ç»„æœ€å¤§å€¼
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
    // 16. æ•°ç»„æœ€å°å€¼
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
    // 17. æ•°ç»„æ±‚å’Œ
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
    // 18. æ•°ç»„å¹³å‡å€¼
    // ============================================
    double avgArr(long long a[], int n)
    {
        if (n <= 0) return 0.0;
        return (double)sumArr(a, n) / n;
    }

    // ============================================
    // 19. åè½¬æ•°ç»„
    // ============================================
    void reverseArr(long long a[], int n)
    {
        for (int i = 0; i < n / 2; i++)
        {
            std::swap(a[i], a[n - i - 1]);
        }
    }

    // ============================================
    // 20. ç»Ÿè®¡å…ƒç´ å‡ºç°æ¬¡æ•°
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
    // 21. è½¬å¤§å†™
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
    // 22. è½¬å°å†™
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
    // 23. å­—ç¬¦ä¸²é•¿åº¦
    // ============================================
    int strLen(const std::string& str)
    {
        return (int)str.length();
    }

    // ============================================
    // 24. åè½¬å­—ç¬¦ä¸²
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
    // 25. å­—æ¯å¼‚ä½è¯åˆ¤æ–­
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
    // 26. ç»Ÿè®¡å…ƒéŸ³å­—æ¯æ•°
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
    // 27. ç»Ÿè®¡è¾…éŸ³å­—æ¯æ•°
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
    // 28. ç»å¯¹å€¼
    // ============================================
    long long absInt(long long n)
    {
        return n < 0 ? -n : n;
    }

    // ============================================
    // 29. ä¸‰æ•°æœ€å¤§å€¼
    // ============================================
    long long max3(long long a, long long b, long long c)
    {
        return std::max(std::max(a, b), c);
    }

    // ============================================
    // 30. ä¸‰æ•°æœ€å°å€¼
    // ============================================
    long long min3(long long a, long long b, long long c)
    {
        return std::min(std::min(a, b), c);
    }

    // ============================================
    // 31. åˆ¤æ–­å¶æ•°
    // ============================================
    bool isEven(long long n)
    {
        return n % 2 == 0;
    }

    // ============================================
    // 32. åˆ¤æ–­å¥‡æ•°
    // ============================================
    bool isOdd(long long n)
    {
        return n % 2 != 0;
    }

    // ============================================
    // 33. å¹³æ–¹
    // ============================================
    long long sqr(long long n)
    {
        return n * n;
    }

    // ============================================
    // 34. åˆ¤æ–­æ˜¯å¦ä¸º 2 çš„å¹‚
    // ============================================
    bool isPowerOfTwo(long long n)
    {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }

    // ============================================
    // 35. äºŒè¿›åˆ¶ä¸­ 1 çš„ä¸ªæ•°ï¼ˆè´Ÿæ•°æŒ‰è¡¥ç ç»Ÿè®¡ï¼‰
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
    // 36. åè½¬ä½ 32 ä½æ¯”ç‰¹
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
    // 37. åˆ¤æ–­é—°å¹´
    // ============================================
    bool isLeapYear(int y)
    {
        if (y < 0) y = -y;
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    // ============================================
    // 38. æœˆä»½å¤©æ•°
    // ============================================
    int daysInMonth(int y, int m)
    {
        if (m < 1 || m > 12) return -1;

        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (m == 2 && isLeapYear(y)) return 29;
        return days[m - 1];
    }

    // ============================================
    // 39. åˆ¤æ–­æ—¥æœŸæ˜¯å¦åˆæ³•
    // ============================================
    bool isValidDate(int y, int m, int d)
    {
        if (m < 1 || m > 12) return false;
        if (d < 1) return false;

        int maxDay = daysInMonth(y, m);
        if (maxDay == -1) return false;

        return d <= maxDay;
    }
        // ============================================
    // 40. ÅĞ¶ÏÊı×éÊÇ·ñÉıĞò
    // ============================================
    bool isSorted(long long a[], int n)
    {
        if (n <= 1) return true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1]) return false;
        }
        return true;
    }

    // ============================================
    // 41. ²éÕÒÔªËØÊ×´Î³öÏÖÎ»ÖÃ£¨²»´æÔÚ·µ»Ø -1£©
    // ============================================
    int findIndex(long long a[], int n, long long x)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x) return i;
        }
        return -1;
    }

    // ============================================
    // 42. ÅĞ¶Ï×Ö·û´®ÊÇ·ñÎª»ØÎÄ
    // ============================================
    bool isPalindromeStr(const std::string& str)
    {
        int left = 0;
        int right = str.length() - 1;
        while (left < right)
        {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    // ============================================
    // 43. Í³¼Æµ¥´ÊÊıÁ¿£¨ÒÔ¿Õ¸ñ·Ö¸ô£©
    // ============================================
    int countWords(const std::string& str)
    {
        if (str.empty()) return 0;

        int count = 0;
        bool inWord = false;

        for (char c : str)
        {
            if (c == ' ' || c == '\t' || c == '\n')
            {
                inWord = false;
            }
            else if (!inWord)
            {
                inWord = true;
                count++;
            }
        }
        return count;
    }

    // ============================================
    // 44. Á¢·½
    // ============================================
    long long cube(long long n)
    {
        return n * n * n;
    }

    // ============================================
    // 45. ÅĞ¶ÏÍêÈ«Æ½·½Êı
    // ============================================
    bool isPerfectSquare(long long n)
    {
        if (n < 0) return false;
        if (n == 0 || n == 1) return true;

        long long left = 1, right = n;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;
            if (sq == n) return true;
            if (sq < n) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }

    // ============================================
    // 46. ÅĞ¶ÏÍêÈ«Á¢·½Êı
    // ============================================
    bool isPerfectCube(long long n)
    {
        if (n < 0) n = -n;
        if (n == 0 || n == 1) return true;

        long long left = 1, right = n;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long cb = mid * mid * mid;
            if (cb == n) return true;
            if (cb < n) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }

    // ============================================
    // 47. ÓÃÎ»ÔËËãÅĞ¶ÏÅ¼Êı
    // ============================================
    bool isEvenBit(long long n)
    {
        return (n & 1) == 0;
    }

    // ============================================
    // 48. ¼ÆËãĞÇÆÚ¼¸£¨0=ÖÜÈÕ, 1=ÖÜÒ», ... 6=ÖÜÁù£©
    // ============================================
    int dayOfWeek(int y, int m, int d)
    {
        // Ê¹ÓÃ»ùÄ·À­¶ûÉ­¹«Ê½
        if (m < 3)
        {
            m += 12;
            y--;
        }
        int c = y / 100;
        int year = y % 100;
        int w = (d + 2 * m + 3 * (m + 1) / 5 + year + year / 4 + c / 4 + 5 * c) % 7;
        return w;
    }

    // ============================================
    // 49. ¼ÆËãÁ½¸öÈÕÆÚÏà²îµÄÌìÊı
    // ============================================
    int daysBetween(int y1, int m1, int d1, int y2, int m2, int d2)
    {
        // ½«ÈÕÆÚ×ª»»Îª×ÜÌìÊı
        auto daysSinceEpoch = [](int y, int m, int d)
        {
            int days = 0;
            // ´Ó¹«Ôª1Äê¿ªÊ¼ÀÛ¼Ó£¨¼ò»¯°æ£¬²»¿¼ÂÇ¹«ÔªÇ°µÄ¸´ÔÓÇé¿ö£©
            // ÕâÀïÖ»´¦ÀíÕıÊıÄê·İ£¬ÇÒ y1/y2 >= 1
            for (int i = 1; i < y; i++)
            {
                days += isLeapYear(i) ? 366 : 365;
            }
            for (int i = 1; i < m; i++)
            {
                days += daysInMonth(y, i);
            }
            days += d - 1;
            return days;
        };

        int days1 = daysSinceEpoch(y1, m1, d1);
        int days2 = daysSinceEpoch(y2, m2, d2);
        return days2 - days1;
    }
}
