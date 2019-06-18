//	// read in binary, output decimal
//	Given a Binary Number B, Print its decimal equivalent.
//	
//	Input:
//	The first line of input contains an integer T denoting the number of test cases. 
//	The description of T test cases follow. Each test case contains a single Binary number B. 
//	
//	Output: 
//	For each testcase, in a new line, print each Decimal number in new line.
//	
//	Constraints:
//	1 <= T <= 100
//	1 <= Digits in Binary <= 16
//	
//	Example:
//	Input:
//	2
//	10001000
//	101100
//	Output:
//	136
//	44
//	
//	
#include <iostream>
using namespace std;

int main() {
	unsigned int n_testcases(0);
	cin >> n_testcases;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	while (0 < n_testcases--) {
		string line;
		unsigned int value(0);
		getline(cin,line);
		for (const char& i : line) {
			value <<= 1;
			value|=i-'0';
		}
	
		cout << value << endl;
	}
	return 0;
}
