#include <iostream>
using namespace std;

int main(int const argc, const char * const argv[]) {
	size_t T;
	cin >> T;
	while (T--)
	{
	    string s;
	    int count[2] {0,0};
	    cin >> s;
	    for (int i = 0; i<s.size(); ++i)
            if (s[i] == '1') ++count[i%2];
            
	    int ans = (count[0] - count[1]) % 3 ? 0 : 1;
	    cout << ans << endl;
	}

	return 0;
}

/*
Given a binary number, write a program that prints 1 if given binary number is a multiple of 3.  Else prints 0. The given number can be big upto 2^100. It is recommended to finish the task using one traversal of input binary string.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
Each case contains a string containing 0's and 1's.

Output:
For each test case, output a 1 if string is multiple of 3, else 0.

Constraints:
1<=T<=100
1<=Length of Input String<=100

Example:
Input:
2
011
100

Output:
1
0

*/
