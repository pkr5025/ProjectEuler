﻿/* Project Euler Problem 26 from projecteuler.net
 by Philip Klein-Rodick
 
 Problem Statement:
 A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

 1/2	= 	0.5
 1/3	= 	0.(3)
 1/4	= 	0.25
 1/5	= 	0.2
 1/6	= 	0.1(6)
 1/7	= 	0.(142857)
 1/8	= 	0.125
 1/9	= 	0.(1)
 1/10	= 	0.1
 Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

 Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 
 Solution: 983
 Idea: First, I implemented a prime sieve as only numbers of the form 1/p for a prime p will have the longest recurring cycle.
 Then, note the following, the problem is equivalent to asking what is the n for 1<n<1000 that gives the largest k in the problem:
 find the least k such that 10^k = 1 mod n ( See mathworld.wolfram.com/DecimalExpansion.html for more information )
 I then solved this equivalent problem.
 */

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

//Prime sieve returns a vector of bools such that the value of the ith index returns true if i is composite
vector<bool> primesieve(int upperbound) {
	int upperboundalgorithm = ((int)sqrt((double)upperbound));
	vector<bool> composite(upperbound + 1, 0);
	for (int i = 2; i < upperboundalgorithm; i++) {
		if (!composite[i]) {
			for (int k = i * i; k < upperbound + 1; k += i) {
				composite[k] = true;
			}
		}
	}
	return composite;
}
int main()
{
	int k;							
	int value;						
	int upperbound = 1000;			
	int longestrecurring = 0;		
	vector<bool> composite = primesieve(upperbound);
	
	for (int i = 6; i < upperbound; i++) {
		if (!composite[i]) {
			value = 10;
			for (k = 1; value %i != 1; k++){
				value = (value * 10) %i;
			}
			if (k > longestrecurring)
				longestrecurring = i;
		}
	}
	cout << longestrecurring<<endl;
}

