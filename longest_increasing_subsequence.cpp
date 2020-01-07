#include <iterator>
#include <vector>
using namespace std;


// version 1
int main(int argc, char const * const argv[]) {
	//code
	int T;
	chrono::time_point<chrono::system_clock> t1 { chrono::system_clock::now()};
	cin >> T;
	while (T--){
		int N; 
		cin >> N;
		int a[N];
		copy_n(istream_iterator<int>(cin), N, a);
		vector<int> ans;
		ans.emplace_back(a[0]);
		for (int i=1; i<N; ++i) {
			if (a[i] > *(ans.end()-1))
				ans.emplace_back(a[i]);
			else {
				vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), a[i]);
				*it = a[i];
			}
		}
		cout << ans.size() << endl;;
	}
	cout <<  (chrono::system_clock::now() - t1).count() << endl;
	return 0;
}

// version 2

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(int const argc, const char * const argv[]) {
	int T;
	cin >> T;
	while (T--)
	{
	    int N;
	    cin >> N;
	    vector<int> v;
	    v.reserve(N);
	    copy_n(istream_iterator<int>(cin), N, v.begin());
	    vector<int> dp(N, 0);
	    dp[0] = 1;
	    int maxx = 1;
	    for (int i=1; i<N; ++i)
	    {
	            int submax = 0;
	            for (int j = 0; j < i; ++j)
	                if (v[j] < v[i])
	                    submax = max(submax,dp[j]);

	            dp[i] = submax+1;
	            maxx = max(dp[i], maxx);

        }
        cout << maxx << endl;

	}
	return 0;
}

/*
Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Output:
For each testcase, in a new line, print the Max length of the subsequence in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 300

Example:
Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3

Explanation:
Testcase 2: Longest increasing subsequence is of size 3 with elements (there are many subsequence, but listing one of them): 5 7 9.



2
9
15 27 14 38 26 55 46 65 85
9
2 6 3 4 1 2 9 5 8

Output: 
6
5


*/
