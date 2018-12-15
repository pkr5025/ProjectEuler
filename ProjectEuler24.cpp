// Project Euler Problem 24 from projecteuler.net
// by Philip Klein-Rodick
// Solution: 2 7 8 3 9 1 5 4 6 0

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

