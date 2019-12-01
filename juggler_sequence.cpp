#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	while (T--) {
	    int N;
	    cin >> N;
	    cout << N << " ";
	    long next = 0L;
	    vector<long> ans;
	    while (N != 1) {
            next = N%2 ? pow(sqrt(N),3) : sqrt(N);
            N = next;
            cout << N << " ";
	    }
	    cout << endl;
	}
	return 0;
}
/*
Juggler Sequence is a series of integer number in which the first term starts with a positive integer number a and the remaining terms are generated from the immediate previous term using the below recurrence relation:

 a_(k+1)={|_a_k^(1/2)_|   for even a_k; |_a_k^(3/2)_|   for odd a_k, 

Given a number N your task is to print the space separated Juggler Sequence for this number as the first term of the sequence.
 

Examples:

Input: 9
Output: 9, 27, 140, 11, 36, 6, 2, 1
We start with 9 and use above formula to get
next terms.

Input: 6
Output: 6, 2, 1

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each line contains an integer N.

Output:
For each test case in a new line print the space separated juggler sequence for  number N as the first term of the sequence.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
9
6
Output:
9  27 140 11 36 6 2 1
6 2 1
*/
