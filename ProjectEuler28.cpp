/* Project Euler Problem 28 from projecteuler.net
 by Philip Klein-Rodick
 Problem Statement:
 
 Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 
 21 22 23 24 25
 20  7  8  9 10
 19  6  1  2 11
 18  5  4  3 12
 17 16 15 14 13

 It can be verified that the sum of the numbers on the diagonals is 101.

 What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

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
