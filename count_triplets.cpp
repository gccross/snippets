#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char const * const argv[]) {
	size_t T;
	cin >> T;
	while (T--) {
	    size_t N;
	    cin >> N;
	    int a[N];
	    copy_n(istream_iterator<int>(cin), N, a);
        sort (a, a+N );
        
        int count = 0;

	    for (int i = N-2; i>=0; --i) {
			// compare every element in the sequence against the other.
			int len = N;
			for (int j = i-1; j>=0; --j) {  

				// short circuits
				if (a[i] + a[j] < a[i+1] )  break; // if sum less than next after larger operand, don't waste time looking further
				if (a[i] + a[j] > a[len-1]) { --j; continue; }  // if sum greater than greatest number, continue to reduce smaller operand

				int* p = lower_bound(a+i+1, a+len, a[i] + a[j]) ; // now we're in range, so search
				if (*p == a[i] + a[j]) 
					++count; // increase count if found
				len = distance(a,p); // impossible to find greater than a[i]+a[j] as we reduce j, so don't bother looking past it.
			}
		}
	    
	    cout << (count == 0 ? -1 : count) << endl;
	}
	return 0;
}
//Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
//
//Input:
//The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated elements.
//
//Output:
//For each test case, print the count of all triplets, in new line. If no such triplets can form, print "-1".
//
//Constraints:
//1 <= T <= 100
//3 <= N <= 105
//1 <= A[i] <= 106
//
//Example:
//Input:
//2
//4
//1 5 3 2
//3
//3 2 7
//Output:
//2
//-1
//
//Explanation:
//Testcase 1: There are 2 triplets: 1 + 2 = 3 and 3 +2 = 5
//

