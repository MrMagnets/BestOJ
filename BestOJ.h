#pragma once
#include <string>
/*
* @file BestOJ.h
* @brief BestOJ 常用的OJ函数库
* @author Magnet
* @version v1.2.6
*/
namespace BestOJ
{
	// ========== 幂运算 ==========
	long long power(long long a, long long b);

	// ========== 数论 / 取模 ==========
	long long gcd(long long a, long long b);
	long long lcm(long long a, long long b);
	bool isPrime(long long n);
	bool isPrimeFast(long long n);
	long long pmod(long long a, long long b, long long mod);
	long long gcdExtended(long long a, long long b, long long& x, long long& y);
	long long modInverse(long long a, long long mod);

	// ========== 进制转换 ==========
	long long tBase(long long n, int base);   // 2 <= Base <= 8
	long long fBase(long long n, int base);   // 2 <= Base <= 8

	// ========== 排列组合 ==========
	long long Permu(long long n, long long m);
	long long Combi(long long n, long long m);
	long long fact(long long n);
	bool nextPermutation(long long a[], int n);

	// ========== 数列 / 数字 ==========
	long long fib(long long n);
	bool isPalind(long long n);
	long long numSum(long long n);
	long long rvsNum(long long n);
	bool isArmstrong(long long n);

	// ========== 排序 ==========
	void quickSort(long long a[], int l, int r);
	void mergeSort(long long a[], int l, int r);
	void bubbleSort(long long a[], int n);
	void selectionSort(long long a[], int n);
	void insertionSort(long long a[], int n);
	void shellSort(long long a[], int n);
	void heapSort(long long a[], int n);
	void countingSort(long long a[], int n, long long maxVal);
	void radixSort(long long a[], int n);
	void bucketSort(long long a[], int n);
	void sortRange(long long a[], int l, int r);
	void sortDescending(long long a[], int n);

	// ========== 搜索 ==========
	int binarySearch(long long a[], int n, long long x);

	// ========== 数组操作 ==========
	long long maxVal(long long a[], int n);
	long long minVal(long long a[], int n);
	long long sumArr(long long a[], int n);
	double avgArr(long long a[], int n);
	void reverseArr(long long a[], int n);
	int countOccur(long long a[], int n, long long x);
	bool isSorted(long long a[], int n);
	bool isDescending(long long a[], int n);
	int findIndex(long long a[], int n, long long x);
	long long maxSubarraySum(long long a[], int n);
	void rotateArray(long long a[], int n, int k);
	int removeDuplicates(long long a[], int n);

	// ========== 字符串操作 ==========
	std::string toUpper(const std::string& str);
	std::string toLower(const std::string& str);
	int strLen(const std::string& str);
	std::string strReverse(const std::string& str);
	bool isAnagram(const std::string& a, const std::string& b);
	int countVowels(const std::string& str);
	int countConsonants(const std::string& str);
	bool isPalindromeStr(const std::string& str);
	int countWords(const std::string& str);
	std::string replaceChar(const std::string& str, char oldChar, char newChar);
	std::string longestCommonPrefix(const std::string& a, const std::string& b);
	int editDistance(const std::string& a, const std::string& b);

	// ========== 数学工具 ==========
	long long absInt(long long n);
	long long max3(long long a, long long b, long long c);
	long long min3(long long a, long long b, long long c);
	bool isEven(long long n);
	bool isOdd(long long n);
	long long sqr(long long n);
	long long cube(long long n);
	bool isPerfectSquare(long long n);
	bool isPerfectCube(long long n);

	// ========== 位运算 ==========
	bool isPowerOfTwo(long long n);
	bool isPowerOfFour(long long n);
	int countBits(long long n);
	long long reverseBits(long long n);
	bool isEvenBit(long long n);
	long long lowbit(long long n);

	// ========== 日期工具 ==========
	bool isLeapYear(int y);
	int daysInMonth(int y, int m);
	bool isValidDate(int y, int m, int d);
	int dayOfWeek(int y, int m, int d);
	int daysBetween(int y1, int m1, int d1, int y2, int m2, int d2);
	int age(int y1, int m1, int d1, int y2, int m2, int d2);
}
