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
	    
		int count{0};
		
		auto cmp = [&a](size_t i, size_t j, size_t k) {
			return a[i] + a[j] == a[k];
		};

		auto cmp_mid = [&a, &cmp](size_t i) {
			return cmp(i-2,i-1,i) + cmp(i-1,i+1,i) + cmp(i+1,i+2,i);
		};

		// try short-circuit for N==3 or 4
		count = cmp(0,1,2) + cmp(0,2,1) + cmp(1,2,0);
		if (3 == N) return count;
		if (4 == N) return count + cmp(1,2,3) + cmp(2,3,1) + cmp(1,3,2);

		// else startover with single-index strategy
		count = 0;
		
		// do mid, because that is the most fun
		for (size_t i = 2; i < N-2; ++i)
			count += cmp_mid(i);
		
		// now left end
		count += cmp(1,2,0) + cmp(0,2,1) + cmp(2,3,1);

		// right end
		count += cmp(N-3,N-2,N-1) + cmp(N-3,N-1,N-2) + cmp(N-4,N-3,N-2);

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
