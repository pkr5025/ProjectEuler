/* Project Euler Problem 24 from projecteuler.net
 by Philip Klein-Rodick
 Problem Statement:
 A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

 012   021   102   120   201   210

 What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 
 Idea: Brute force using the next_permutation command
 Solution: 2 7 8 3 9 1 5 4 6 0
*/

#include <iostream>
#include <algorithm>	//next_permutation

using namespace std;



int main()
{
	int permute[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 999999; i++) {
		next_permutation(permute, permute + 10);
	}
	for (int i = 0; i < 10; i++) {
		cout << permute[i] << ' ';
	}

}

