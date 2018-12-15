/* Project Euler Problem 28 from projecteuler.net
 by Philip Klein-Rodick
 Solution: 669171001
 Idea: For an n by n spiral, there are (n+1)/2-1 squares (-1 since the first square is an exception since it consists of 
 just the number 1.) For each square, we must add their corner values together. For a given square i, its corner values increase 
 by 2*i as you spiral around.  Given a running sum, we increase it 4 times per square to find the final sum.
 */

#include <iostream>

using namespace std;

int main()
{
	int squares = (1001 + 1) / 2;
	int sum = 1;
	int valueschange;
	int value = 1; //the last value from the previous square
	for (int i = 1; i < squares; ++i) {
		valueschange = 2 * i;
		for (int j = 1; j < 5; j++) {
			sum += value + valueschange * j;
		}
		value += valueschange * 4;
	}
	cout << sum;
	return 0;
}
