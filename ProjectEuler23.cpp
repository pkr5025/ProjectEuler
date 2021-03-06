﻿/* 
 Project Euler Problem 23 from projecteuler.net
 by Philip Klein-Rodick
Problem Statement:
 A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

 A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

 As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

 Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 
 Idea:  Slow bruteforce non-optimized code
 Solution: 4179871

*/
#include <vector>
#include <iostream>
#include <algorithm>// sort
#include<numeric>	//iota
#include <iterator> //inserter

using namespace std;
vector<int> abundantnumbers(int n, int m)
//finds abundant numbers from the lower bound n to the upper bound m inclusive
{
	vector<int> abundant;
	int sum = 1;							//sum of factors 
	for (int i = n; i < m+1; i++) {			//start loop to find abundant numbers from n to m
		for (int k = 2; k< i; k++) {		// start loop to find all factors (NOT JUST PRIME) of potential abundant  numbers
			if (i%k == 0)
				sum += k;
		}
		if (sum > i)
			abundant.push_back(i);
		sum = 1;

	}
	return abundant;
}
vector<int> sumoftwo(vector<int> abundant) 
//given a list of abundant numbers, this gives a vector of all numbers that are the sum of two abundants (includes repeat sums)
{
	vector<int> sumabundant;
	for (int i = 0; i < abundant.size(); i++) {
		for (int k = i; k < abundant.size(); k++) {
			sumabundant.push_back(abundant[i] + abundant[k]);
		}
	}
	return sumabundant;

}
int main()
{
	long long sum = 0;
	vector<int> test = abundantnumbers(1, 28123);	//find all abundant numbers from 1 to 28123
	test = sumoftwo(test);							//find all sums of two abundant numbers from 1 to 28123
	sort(begin(test), end(test));
	test.erase(unique(test.begin(), test.end()), test.end());	//erase all duplicate sums
	while (test.back() > 28123) {					//remove all sums larger than 28123
		test.pop_back();
	}

	vector<int> posint(28123);
	iota(begin(posint), end(posint), 1);
	vector<int> diff;
	set_difference(begin(posint), end(posint), begin(test), end(test), inserter(diff, diff.begin()));  
	//find complement of sums of 2 abundant numbers
	//ie, all numbers that are not the sum of two abundant numbers
	while (diff.empty() == false) {
		sum += diff.back(); //add them up!
		diff.pop_back();
	}
	cout << sum << endl;

	return 0;
}
