#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	while (T--)
	{
	    int N;
	    cin >> N;
	    vector<int> v(N);
	    copy_n(istream_iterator<int>(cin), N, v.begin());
	    
	    int ans = -1;
	    int left_greatest = v[0];
	    int candidate = 0;

	    for (int i=1; i<N; ++i)
	    {
	        left_greatest = max(left_greatest, v[i-1]);
	        if (!candidate)
	        {
	            if (left_greatest <= v[i])
                {
	                candidate = i;
                }
	        }
	        else
	        {
	            if (v[candidate] > v[i]) 
	            {
                    candidate = 0;
	            }
	        }
	    }
	    
	    
	    if (!candidate || candidate == N-1) ans = -1;
	    else ans = v[candidate];
	    cout << ans << endl;
	        
	}
	return 0;
}
/*
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element present in array then print -1.

Constraints:
1 <= T <= 100
3 <= N <= 106
1 <= A[i] <= 106

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7
Explanation:
Testcase 1 : Elements on left of 5 are smaller than 5 and on right of it are greater than 5.

Testcases:
2
16
37 40  22 13 28 41 10 14 27 41 42 43 47 48 49 50
5
3 3 3 3 3
7
2 3 17 23 12 8 17
3
8
10 3 11 3 4 8 12 16
5
3 3 3 3 3
7
2 3 17 23 12 8 17




*/


