/* Project Euler Problem 26 from projecteuler.net
 by Philip Klein-Rodick
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

