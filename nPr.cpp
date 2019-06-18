//	Write a program to calculate nPr. nPr represents n permutation r and value of nPr is (n!) / (n-r)!.
//	
//	Input: 
//	The first line of the input contains T denoting the number of testcases. 
//	T testcases follow. First line of the test case will be the value of n and r respectively.
//	
//	Output:
//	For each test case, in a new line, output will be the value of nPr.
//	
//	Constraints:
//	1 <= T <= 100
//	1 <= n,r <= 20
//	n >= r
//	
//	Example:
//	Input:
//	2
//	2 1
//	10 4
//	Output:
//	2
//	5040

#include <iostream>
using namespace std;

unsigned long fact(unsigned x)
{
	return 0==x ?  1: x*fact(x-1) ;
}
int main(int argc, const char* const arg[]) {

	unsigned n_testcases(0);
	cin >> n_testcases;
	while (n_testcases--) {
	
		unsigned n(0), r(0);
		cin >> n >> r;
		cout << fact(n) / fact (n-r) << endl;
	}
	
	return 0;
}

