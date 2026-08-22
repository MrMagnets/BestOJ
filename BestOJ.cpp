#include "BestOJ.h"
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

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
	// 35. 二进制中 1 的个数
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

	// ============================================
	// 40. 判断数组是否升序
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
	// 41. 查找元素首次出现位置
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
	// 42. 判断字符串是否为回文
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
	// 43. 统计单词数量
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
	// 44. 立方
	// ============================================
	long long cube(long long n)
	{
		return n * n * n;
	}

	// ============================================
	// 45. 判断完全平方数
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
	// 46. 判断完全立方数
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
	// 47. 用位运算判断偶数
	// ============================================
	bool isEvenBit(long long n)
	{
		return (n & 1) == 0;
	}

	// ============================================
	// 48. 计算星期几（基姆拉尔森公式）
	// ============================================
	int dayOfWeek(int y, int m, int d)
	{
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
	// 49. 计算两个日期相差的天数
	// ============================================
	int daysBetween(int y1, int m1, int d1, int y2, int m2, int d2)
	{
		auto daysSinceEpoch = [](int y, int m, int d)
		{
			int days = 0;
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

	// ============================================
	// 50. 判断数组是否降序
	// ============================================
	bool isDescending(long long a[], int n)
	{
		if (n <= 1) return true;
		for (int i = 1; i < n; i++)
		{
			if (a[i] > a[i - 1]) return false;
		}
		return true;
	}

	// ============================================
	// 51. 快速判断质数（6k±1 优化）
	// ============================================
	bool isPrimeFast(long long n)
	{
		if (n <= 1) return false;
		if (n == 2 || n == 3) return true;
		if (n % 2 == 0 || n % 3 == 0) return false;

		for (long long i = 5; i * i <= n; i += 6)
		{
			if (n % i == 0 || n % (i + 2) == 0) return false;
		}
		return true;
	}

	// ============================================
	// 52. 替换字符串中所有指定字符
	// ============================================
	std::string replaceChar(const std::string& str, char oldChar, char newChar)
	{
		std::string result = str;
		for (char& c : result)
		{
			if (c == oldChar) c = newChar;
		}
		return result;
	}

	// ============================================
	// 53. 快速排序
	// ============================================
	void quickSort(long long a[], int l, int r)
	{
		if (l >= r) return;
		int i = l, j = r;
		long long pivot = a[(l + r) / 2];
		while (i <= j)
		{
			while (a[i] < pivot) i++;
			while (a[j] > pivot) j--;
			if (i <= j)
			{
				std::swap(a[i], a[j]);
				i++;
				j--;
			}
		}
		quickSort(a, l, j);
		quickSort(a, i, r);
	}

	// ============================================
	// 54. 归并排序
	// ============================================
	void mergeSort(long long a[], int l, int r)
	{
		if (l >= r) return;
		int mid = (l + r) / 2;
		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, r);

		std::vector<long long> temp(r - l + 1);
		int i = l, j = mid + 1, k = 0;
		while (i <= mid && j <= r)
		{
			if (a[i] <= a[j]) temp[k++] = a[i++];
			else temp[k++] = a[j++];
		}
		while (i <= mid) temp[k++] = a[i++];
		while (j <= r) temp[k++] = a[j++];
		for (int p = 0; p < k; p++) a[l + p] = temp[p];
	}

	// ============================================
	// 55. 二分查找
	// ============================================
	int binarySearch(long long a[], int n, long long x)
	{
		int l = 0, r = n - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (a[mid] == x) return mid;
			if (a[mid] < x) l = mid + 1;
			else r = mid - 1;
		}
		return -1;
	}

	// ============================================
	// 56. 最长公共前缀
	// ============================================
	std::string longestCommonPrefix(const std::string& a, const std::string& b)
	{
		int len = std::min(a.length(), b.length());
		int i = 0;
		while (i < len && a[i] == b[i]) i++;
		return a.substr(0, i);
	}

	// ============================================
	// 57. 编辑距离
	// ============================================
	int editDistance(const std::string& a, const std::string& b)
	{
		int n = a.length(), m = b.length();
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
		for (int i = 0; i <= n; i++) dp[i][0] = i;
		for (int j = 0; j <= m; j++) dp[0][j] = j;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (a[i - 1] == b[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
			}
		}
		return dp[n][m];
	}

	// ============================================
	// 58. 最大子数组和（Kadane 算法）
	// ============================================
	long long maxSubarraySum(long long a[], int n)
	{
		long long current = a[0], best = a[0];
		for (int i = 1; i < n; i++)
		{
			current = std::max(a[i], current + a[i]);
			best = std::max(best, current);
		}
		return best;
	}

	// ============================================
	// 59. 循环右移 k 位
	// ============================================
	void rotateArray(long long a[], int n, int k)
	{
		k %= n;
		if (k < 0) k += n;
		if (k == 0) return;
		reverseArr(a, n);
		reverseArr(a, k);
		reverseArr(a + k, n - k);
	}

	// ============================================
	// 60. 原地去重
	// ============================================
	int removeDuplicates(long long a[], int n)
	{
		if (n <= 1) return n;
		quickSort(a, 0, n - 1);
		int j = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i] != a[j]) a[++j] = a[i];
		}
		return j + 1;
	}

	// ============================================
	// 61. 判断阿姆斯特朗数
	// ============================================
	bool isArmstrong(long long n)
	{
		if (n < 0) return false;
		long long original = n, sum = 0;
		int digits = 0, temp = n;
		while (temp > 0) { temp /= 10; digits++; }
		temp = n;
		while (temp > 0)
		{
			int digit = temp % 10;
			sum += power(digit, digits);
			temp /= 10;
		}
		return sum == original;
	}

	// ============================================
	// 62. 扩展欧几里得算法
	// ============================================
	long long gcdExtended(long long a, long long b, long long& x, long long& y)
	{
		if (b == 0) { x = 1; y = 0; return a; }
		long long x1, y1;
		long long g = gcdExtended(b, a % b, x1, y1);
		x = y1;
		y = x1 - (a / b) * y1;
		return g;
	}

	// ============================================
	// 63. 模逆元
	// ============================================
	long long modInverse(long long a, long long mod)
	{
		long long x, y;
		long long g = gcdExtended(a, mod, x, y);
		if (g != 1) return -1;
		return (x % mod + mod) % mod;
	}

	// ============================================
	// 64. 返回最低位1的值
	// ============================================
	long long lowbit(long long n)
	{
		return n & -n;
	}

	// ============================================
	// 65. 判断是否为4的幂
	// ============================================
	bool isPowerOfFour(long long n)
	{
		if (n <= 0) return false;
		return (n & (n - 1)) == 0 && (n % 3 == 1);
	}

	// ============================================
	// 66. 下一个排列
	// ============================================
	bool nextPermutation(long long a[], int n)
	{
		int i = n - 2;
		while (i >= 0 && a[i] >= a[i + 1]) i--;
		if (i < 0) return false;
		int j = n - 1;
		while (a[j] <= a[i]) j--;
		std::swap(a[i], a[j]);
		int l = i + 1, r = n - 1;
		while (l < r) std::swap(a[l++], a[r--]);
		return true;
	}

	// ============================================
	// 67. 计算年龄
	// ============================================
	int age(int y1, int m1, int d1, int y2, int m2, int d2)
	{
		int years = y2 - y1;
		if (m2 < m1 || (m2 == m1 && d2 < d1)) years--;
		return years;
	}

	// ============================================
	// 68. 冒泡排序
	// ============================================
	void bubbleSort(long long a[], int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			bool swapped = false;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					std::swap(a[j], a[j + 1]);
					swapped = true;
				}
			}
			if (!swapped) break;
		}
	}

	// ============================================
	// 69. 选择排序
	// ============================================
	void selectionSort(long long a[], int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int minIdx = i;
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] < a[minIdx]) minIdx = j;
			}
			if (minIdx != i) std::swap(a[i], a[minIdx]);
		}
	}

	// ============================================
	// 70. 插入排序
	// ============================================
	void insertionSort(long long a[], int n)
	{
		for (int i = 1; i < n; i++)
		{
			long long key = a[i];
			int j = i - 1;
			while (j >= 0 && a[j] > key)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = key;
		}
	}

	// ============================================
	// 71. 希尔排序
	// ============================================
	void shellSort(long long a[], int n)
	{
		for (int gap = n / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < n; i++)
			{
				long long temp = a[i];
				int j = i;
				while (j >= gap && a[j - gap] > temp)
				{
					a[j] = a[j - gap];
					j -= gap;
				}
				a[j] = temp;
			}
		}
	}

	// ============================================
	// 72. 堆排序辅助函数
	// ============================================
	void heapify(long long a[], int n, int i)
	{
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < n && a[l] > a[largest]) largest = l;
		if (r < n && a[r] > a[largest]) largest = r;
		if (largest != i)
		{
			std::swap(a[i], a[largest]);
			heapify(a, n, largest);
		}
	}

	// ============================================
	// 73. 堆排序
	// ============================================
	void heapSort(long long a[], int n)
	{
		for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
		for (int i = n - 1; i > 0; i--)
		{
			std::swap(a[0], a[i]);
			heapify(a, i, 0);
		}
	}

	// ============================================
	// 74. 计数排序
	// ============================================
	void countingSort(long long a[], int n, long long maxVal)
	{
		if (n <= 1) return;
		std::vector<long long> count(maxVal + 1, 0);
		for (int i = 0; i < n; i++) count[a[i]]++;
		int idx = 0;
		for (long long i = 0; i <= maxVal; i++)
		{
			while (count[i] > 0)
			{
				a[idx++] = i;
				count[i]--;
			}
		}
	}

	// ============================================
	// 75. 基数排序
	// ============================================
	void radixSort(long long a[], int n)
	{
		if (n <= 1) return;
		long long mx = maxVal(a, n);
		std::vector<long long> output(n);
		for (long long exp = 1; mx / exp > 0; exp *= 10)
		{
			int count[10] = {0};
			for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
			for (int i = 1; i < 10; i++) count[i] += count[i - 1];
			for (int i = n - 1; i >= 0; i--)
			{
				output[count[(a[i] / exp) % 10] - 1] = a[i];
				count[(a[i] / exp) % 10]--;
			}
			for (int i = 0; i < n; i++) a[i] = output[i];
		}
	}

	// ============================================
	// 76. 桶排序
	// ============================================
	void bucketSort(long long a[], int n)
	{
		if (n <= 1) return;
		long long minV = minVal(a, n);
		long long maxV = maxVal(a, n);
		if (minV == maxV) return;

		int bucketCount = n;
		std::vector<std::vector<long long>> buckets(bucketCount);
		for (int i = 0; i < n; i++)
		{
			int idx = (int)((a[i] - minV) * 1.0 / (maxV - minV + 1) * bucketCount);
			if (idx >= bucketCount) idx = bucketCount - 1;
			buckets[idx].push_back(a[i]);
		}
		int idx = 0;
		for (int i = 0; i < bucketCount; i++)
		{
			insertionSort(buckets[i].data(), buckets[i].size());
			for (long long val : buckets[i]) a[idx++] = val;
		}
	}

	// ============================================
	// 77. 区间排序
	// ============================================
	void sortRange(long long a[], int l, int r)
	{
		if (l < 0 || r < l) return;
		quickSort(a, l, r);
	}

	// ============================================
	// 78. 降序排序
	// ============================================
	void sortDescending(long long a[], int n)
	{
		quickSort(a, 0, n - 1);
		reverseArr(a, n);
	}
}
