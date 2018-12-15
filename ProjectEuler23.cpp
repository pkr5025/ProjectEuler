// Project Euler Problem 23 from projecteuler.net
// by Philip Klein-Rodick
// Bruteforce non-optimized code
// Solution: 4179871

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