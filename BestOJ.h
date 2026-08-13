#pragma once
#include <bits/stdc++.h>
/*
* @file BestOJ.h
* @brief BestOJ ¸üºÃµÄOJ¿â
* @author Magnet ´ÅÌú
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
}
