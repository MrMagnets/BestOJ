#pragma once
#include <string>
/*
* @file BestOJ.h
* @brief BestOJ 常用的OJ函数库
* @author Magnet
* @version Beta 1.0
*/
namespace BestOJ
{
	long long power(long long a,long long b);
	long long gcd(long long a,long long b);
	long long lcm(long long a,long long b);
	long long pmod(long long a,long long b,long long mod);
	bool isPrime(long long n);
	long long numSum(long long n);
	long long rvsNum(long long n);
	long long tBase(long long n,int base);//2 <= Base <= 8
	long long fBase(long long n,int base);//2 <= Base <= 8
	long long Permu(long long n,long long m);
	long long Combi(long long n,long long m);
	long long fact(long long n);
	long long fib(long long n);
	bool isPalind(long long n);
    long long maxVal(long long a[], int n);
    long long minVal(long long a[], int n);
    long long sumArr(long long a[], int n);
    double avgArr(long long a[], int n);
    void reverseArr(long long a[], int n);
    int countOccur(long long a[], int n, long long x);
    std::string toUpper(const std::string& str);
    std::string toLower(const std::string& str);
    int strLen(const std::string& str);
    std::string strReverse(const std::string& str);
    bool isAnagram(const std::string& a, const std::string& b);
    int countVowels(const std::string& str);
    int countConsonants(const std::string& str);
    long long absInt(long long n);
    long long max3(long long a, long long b, long long c);
    long long min3(long long a, long long b, long long c);
    bool isEven(long long n);
    bool isOdd(long long n);
    long long sqr(long long n);
    bool isPowerOfTwo(long long n);
    int countBits(long long n);
    long long reverseBits(long long n);
    bool isLeapYear(int y);
    int daysInMonth(int y, int m);
    bool isValidDate(int y, int m, int d);
    bool isSorted(long long a[], int n);
    int findIndex(long long a[], int n, long long x);
    bool isPalindromeStr(const std::string& str);
    int countWords(const std::string& str);
    long long cube(long long n);
    bool isPerfectSquare(long long n);
    bool isPerfectCube(long long n);
    bool isEvenBit(long long n);
    int dayOfWeek(int y, int m, int d);
    int daysBetween(int y1, int m1, int d1, int y2, int m2, int d2);
    bool isDescending(long long a[], int n);
    bool isPrimeFast(long long n);
    std::string replaceChar(const std::string& str, char oldChar, char newChar);
}
