#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

template <typename It>
class solve 
{
public:
	solve(size_t _N): N(_N) 
	{ 
		memoize = new uint64_t*[N-1];
		for (size_t i = 0; i < N-1; ++i) { 
			memoize[i] = new uint64_t[N];
			fill(memoize[i], memoize[i]+N, numeric_limits<uint64_t>::max());
		}
	}

	uint64_t operator()(It prev, It first, It last)
	{
		instance_first = prev;
		return do_solve(prev, first, last);
	}


private:
	uint64_t do_solve(It prev, It first, It last)
	{
		uint64_t res = 0ULL;
		if (0 == distance(first,last)) return *prev;

		size_t row = distance(instance_first, prev);
		size_t col = distance(instance_first, first);

		if (memoize[row][col] != numeric_limits<uint64_t>::max()) 
			res = memoize[row][col];
		else if (*prev > *first) {

			res = do_solve(prev, ++first, last);
			memoize[row][col] = res;
		}
		else { 
			It next = first;
			++next;

			uint64_t include = *prev + do_solve(first, next, last);
			uint64_t exclude = do_solve(prev, next, last);

			res =  max(include, exclude);
			memoize[row][col] = res;
		}
		return res;
	}

	size_t N;
	uint64_t **memoize;
	It instance_first;
};
int main (int argc, char const * argv[])
{
	ifstream ifs;
	if (1 < argc) {
		ifs.open(argv[1]);
		cin.rdbuf(ifs.rdbuf());
	}
	
	size_t T;
	cin >> T;
	while (T--) {
		size_t N;
		cin >> N;
		uint32_t a[N+1];
		a[0] = 0;
		for (size_t i = 1; i<N+1; ++i) cin >> a[i];
		
		solve<uint32_t*> s(N+1);
		cout << s(a, a+1, a+N+1) << endl;
	}
	return 0;

}

//	Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.
//	
//	Input:
//	The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N(the size of array). The second line of each test case contains array elements.
//	
//	Output:
//	For each test case print the required answer in new line.
//	
//	Constraints:
//	1 ≤ T ≤ 100
//	1 ≤ N ≤ 106
//	1 ≤ Ai ≤ 106
//	
//	Example:
//	Input:
//	2
//	7
//	1 101 2 3 100 4 5
//	4
//	10 5 4 3
//	
//	Output:
//	106
//	10
//	
//	Explanation:
//	Testcase 1: All the increasing subsequences are : (1,101); (1,2,3,100); (1,2,3,4,5). Out of these (1, 2, 3, 100) has maximum sum,i.e., 106.
//	
//	
//	For Input:
//	1
//	6
//	40 5 4 3 20 25
//	Output of Online Judge is:
//	50
//
//	For Input:
//  1
//  42
//  468 335 501 170 725 479 359 963 465 706 146 282 828 962 492 996 943 828 437 392 605 903 154 293 383 422 717 719 896 448 727 772 539 870 913 668 300 36 895 704 812 323
//  
//  Its Correct output is:
//  6974


