#include <iostream>
#include <BestOJ.h>
#include <string>

using namespace std;
using namespace BestOJ;

int main()
{
    cout << "========== BestOJ 测试 ==========\n\n";

    // ==========================================
    // 1. 幂运算
    // ==========================================
    cout << "[幂运算]\n";
    cout << "power(2, 10)  = " << power(2, 10) << endl;   // 1024
    cout << "power(3, 5)   = " << power(3, 5) << endl;    // 243
    cout << endl;

    // ==========================================
    // 2. 数论
    // ==========================================
    cout << "[数论 / 取模]\n";
    cout << "gcd(12, 18)    = " << gcd(12, 18) << endl;      // 6
    cout << "lcm(12, 18)    = " << lcm(12, 18) << endl;      // 36
    cout << "isPrime(17)    = " << isPrime(17) << endl;      // 1 (true)
    cout << "isPrimeFast(17)= " << isPrimeFast(17) << endl;  // 1 (true)
    cout << "pmod(2, 10, 100)= " << pmod(2, 10, 100) << endl; // 24
    cout << "modInverse(3, 7)= " << modInverse(3, 7) << endl; // 5
    cout << endl;

    // ==========================================
    // 3. 进制转换
    // ==========================================
    cout << "[进制转换]\n";
    cout << "tBase(255, 2)  = " << tBase(255, 2) << endl;    // 11111111
    cout << "tBase(255, 8)  = " << tBase(255, 8) << endl;    // 377
    cout << "fBase(11111111, 2) = " << fBase(11111111, 2) << endl; // 255
    cout << endl;

    // ==========================================
    // 4. 排列组合
    // ==========================================
    cout << "[排列组合]\n";
    cout << "Permu(5, 3)    = " << Permu(5, 3) << endl;      // 60
    cout << "Combi(5, 3)    = " << Combi(5, 3) << endl;      // 10
    cout << "fact(5)        = " << fact(5) << endl;          // 120
    long long arr1[] = {1, 2, 3};
    nextPermutation(arr1, 3);
    cout << "nextPermutation(1,2,3) = ";
    for (int i = 0; i < 3; i++) cout << arr1[i] << " ";
    cout << endl;  // 1 3 2
    cout << endl;

    // ==========================================
    // 5. 数列 / 数字
    // ==========================================
    cout << "[数列 / 数字]\n";
    cout << "fib(10)        = " << fib(10) << endl;          // 55
    cout << "isPalind(12321)= " << isPalind(12321) << endl;  // 1 (true)
    cout << "numSum(12345)  = " << numSum(12345) << endl;    // 15
    cout << "rvsNum(12345)  = " << rvsNum(12345) << endl;    // 54321
    cout << "isArmstrong(153)= " << isArmstrong(153) << endl; // 1 (true)
    cout << endl;

    // ==========================================
    // 6. 排序
    // ==========================================
    cout << "[排序]\n";
    long long arr2[] = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr2, 0, 6);
    cout << "quickSort: ";
    for (int i = 0; i < 7; i++) cout << arr2[i] << " ";
    cout << endl;  // 11 12 22 25 34 64 90
    cout << endl;

    // ==========================================
    // 7. 搜索
    // ==========================================
    cout << "[搜索]\n";
    long long arr3[] = {1, 3, 5, 7, 9, 11};
    cout << "binarySearch(7) = " << binarySearch(arr3, 6, 7) << endl; // 3
    cout << endl;

    // ==========================================
    // 8. 数组操作
    // ==========================================
    cout << "[数组操作]\n";
    long long arr4[] = {3, 7, 2, 9, 5};
    cout << "maxVal         = " << maxVal(arr4, 5) << endl;     // 9
    cout << "minVal         = " << minVal(arr4, 5) << endl;     // 2
    cout << "sumArr         = " << sumArr(arr4, 5) << endl;     // 26
    cout << "avgArr         = " << avgArr(arr4, 5) << endl;     // 5.2
    cout << "isSorted       = " << isSorted(arr4, 5) << endl;   // 0 (false)
    cout << "findIndex(7)   = " << findIndex(arr4, 5, 7) << endl; // 1

    long long arr5[] = {5, 3, 1};
    cout << "isDescending   = " << isDescending(arr5, 3) << endl; // 1 (true)

    long long arr6[] = {1, 2, 3, 4, 5};
    rotateArray(arr6, 5, 2);
    cout << "rotateArray(右移2) = ";
    for (int i = 0; i < 5; i++) cout << arr6[i] << " ";
    cout << endl;  // 4 5 1 2 3

    long long arr7[] = {1, 2, 2, 3, 3, 3, 4};
    int len = removeDuplicates(arr7, 7);
    cout << "removeDuplicates = ";
    for (int i = 0; i < len; i++) cout << arr7[i] << " ";
    cout << "  (长度 = " << len << ")" << endl;  // 1 2 3 4

    long long arr8[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "maxSubarraySum  = " << maxSubarraySum(arr8, 9) << endl; // 6
    cout << endl;

    // ==========================================
    // 9. 字符串操作
    // ==========================================
    cout << "[字符串操作]\n";
    cout << "toUpper('hello')         = " << toUpper("hello") << endl;      // HELLO
    cout << "toLower('HELLO')         = " << toLower("HELLO") << endl;      // hello
    cout << "strReverse('hello')      = " << strReverse("hello") << endl;   // olleh
    cout << "isAnagram('abc','cba')   = " << isAnagram("abc", "cba") << endl; // 1 (true)
    cout << "countVowels('hello')     = " << countVowels("hello") << endl;   // 2
    cout << "countConsonants('hello') = " << countConsonants("hello") << endl; // 3
    cout << "isPalindromeStr('aba')   = " << isPalindromeStr("aba") << endl;  // 1 (true)
    cout << "countWords('hello world')= " << countWords("hello world") << endl; // 2
    cout << "replaceChar('hello','l','x') = " << replaceChar("hello", 'l', 'x') << endl; // hexxo
    cout << "longestCommonPrefix('hello','helicopter') = " << longestCommonPrefix("hello", "helicopter") << endl; // hel
    cout << "editDistance('kitten','sitting') = " << editDistance("kitten", "sitting") << endl; // 3
    cout << endl;

    // ==========================================
    // 10. 数学工具
    // ==========================================
    cout << "[数学工具]\n";
    cout << "absInt(-5)      = " << absInt(-5) << endl;        // 5
    cout << "max3(3,7,2)     = " << max3(3, 7, 2) << endl;     // 7
    cout << "min3(3,7,2)     = " << min3(3, 7, 2) << endl;     // 2
    cout << "isEven(4)       = " << isEven(4) << endl;         // 1 (true)
    cout << "isOdd(3)        = " << isOdd(3) << endl;          // 1 (true)
    cout << "sqr(5)          = " << sqr(5) << endl;            // 25
    cout << "cube(3)         = " << cube(3) << endl;           // 27
    cout << "isPerfectSquare(16) = " << isPerfectSquare(16) << endl; // 1 (true)
    cout << "isPerfectCube(27)   = " << isPerfectCube(27) << endl; // 1 (true)
    cout << endl;

    // ==========================================
    // 11. 位运算
    // ==========================================
    cout << "[位运算]\n";
    cout << "isPowerOfTwo(8) = " << isPowerOfTwo(8) << endl;   // 1 (true)
    cout << "isPowerOfFour(16)= " << isPowerOfFour(16) << endl; // 1 (true)
    cout << "countBits(7)    = " << countBits(7) << endl;      // 3
    cout << "lowbit(12)      = " << lowbit(12) << endl;        // 4
    cout << "isEvenBit(4)    = " << isEvenBit(4) << endl;      // 1 (true)
    cout << "reverseBits(1)  = " << reverseBits(1) << endl;    // 2147483648
    cout << endl;

    // ==========================================
    // 12. 日期工具
    // ==========================================
    cout << "[日期工具]\n";
    cout << "isLeapYear(2024) = " << isLeapYear(2024) << endl; // 1 (true)
    cout << "daysInMonth(2024,2) = " << daysInMonth(2024, 2) << endl; // 29
    cout << "isValidDate(2024,2,29) = " << isValidDate(2024, 2, 29) << endl; // 1 (true)
    cout << "dayOfWeek(2024,8,14) = " << dayOfWeek(2024, 8, 14) << endl; // 3 (Wednesday)
    cout << "daysBetween(2024,1,1, 2024,1,31) = " << daysBetween(2024, 1, 1, 2024, 1, 31) << endl; // 30
    cout << "age(2000,1,1, 2024,8,14) = " << age(2000, 1, 1, 2024, 8, 14) << endl; // 24
    cout << endl;

    cout << "========== 测试完成 ==========\n";
    return 0;
}
