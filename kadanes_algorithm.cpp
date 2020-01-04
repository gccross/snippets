#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main (int argc, char const * argv[])
{
	int T;
	cin >> T;
	while (T--)
	{
		int N; 
		cin >> N;
		vector<int> a;
		copy_n(istream_iterator<int>(cin), N, back_inserter(a));
		int submax = a[0], maxx=a[0];

		for (int i=1; i < N+1; ++i)
		{
			submax = max(a[i], submax+a[i]);
			maxx = max(submax, maxx);
		}

		cout << maxx << endl;
	}

	return 0;
}
/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.

Constraints:
1 ≤ T ≤ 110
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107

Example:
Input
3
5
1 2 3 -2 5
4
-1 -2 -3 -4
3
-2 5 -1

Output
9
-1
5

Explanation:
Testcase 1: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

*/
