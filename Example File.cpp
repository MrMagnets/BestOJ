#include <iostream>
#include <BestOJ.h>
using namespace std;
using namespace BestOJ;
int main()
{
	//This is an example file.
	cout << gcd(12, 18) << endl;
	cout << isPrime(28) << " " << isPrime(29) << endl;
	cout << tBase(99,8) << " " << fBase(101101110,2) << endl;
	cout << toUpper("test string") << " " << toLower("TEST STRING") << endl;
	int Year = isLeapYear(2027);
	cout << Year << endl;
	cout << "This is an EXAMPLE FILE! All functions are in BestOJ.cpp / BestOJ.h.";
	return 0;
}
