#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main (int argc, char const * argv[])
{
	cout << "Hello World " __FILE__ << endl;

	size_t T;
	cin >> T;
	while (T--) {

		size_t len;
		cin >> len;
		int arr[len];
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		string line;
		getline(cin,line);
	
		istringstream input(line);
	
		uint64_t temp = 0, mybits = 0, dupbits = 0;
		while (input >> temp) { 
			uint64_t mybit = 1;
			mybit <<= temp;
			if (mybits & mybit && !(dupbits & mybit)) { 
				cout << temp << ' ';
				dupbits |= mybit;
			}
			else mybits |=  mybit;

		} 
		if (!dupbits) cout << -1;
			
		cout << endl;
	}
	return 0;

}
//  Given an array A[], Your task is to complete the function printDuplicates which prints the duplicate elements of the given array. If no duplicate element is found  print -1.
//  
//  Note: Auxiliary Space must be O(1) and Time complexity must be O(n).
//  
//  Input:
//  The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N which denotes number of elements of Array. Second line of each test case contains N space separated integers denoting elements of Array A[].
//  
//  Output:
//  Print the duplicate elements from the array.The order of the output should be as the element found to be repeated.
//  
//  Constraints:
//  1<=T<=100
//  1<=N<=50
//  0<=A[]
//  
//  Example:
//  Input:
//  3
//  4
//  0 3 1 2
//  5
//  2 3 1 2 3 
//  37
//  0 3 12 27 14 6 24 8 21 34 0 33 0 33 1 20 18 14 32 2 24 33 8 8 29 16 35 19 34 32 30 0 35 36 31 2 16
//  Output:
//  -1
//  2 3 
//  0 33 14 24 8 34 32 35 2 16
//  
//  
