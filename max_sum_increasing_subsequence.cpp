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

int main (int argc, char const * argv[])
{
	ifstream ifs;
	if (1 < argc) {
		ifs.open(argv[1]);
		cin.rdbuf(ifs.rdbuf());
	}
	
	chrono::system_clock::time_point t1 = chrono::system_clock::now();
	size_t T;
	cin >> T;
	while (T--) {
		size_t N;
		cin >> N;
		uint32_t a[N];
		for (size_t i = 1; i<N+1; ++i) cin >> a[i];
		
		uint32_t ans[N];
		fill(ans,ans+N,0);
		ans[0] = a[0];
		for (size_t i=1; i<N; ++i) {
			uint32_t maxx = 0;
			for (size_t j=0;j<i; ++j) {
				if (a[j] < a[i] && ans[j] > maxx)
					maxx = ans[j];

			}
			ans[i] = a[i] + maxx;
		}
			
		uint32_t maxx = ans[0];
		for (size_t i=1; i<N; ++i)
			if (ans[i] > maxx) maxx = ans[i];
		cout << maxx << endl;
	}
	cout << "Time: " << (chrono::system_clock::now() - t1).count() << endl;
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

//
//	94
//	726 32 493 143 223 287 65 901 188 361 414 975 271 171 236 834 712 761 897 668 286 551 141 695 696 625 20 126 577 695 659 303 372 467 679 594 852 485 19 465 120 153 801 88 61 927 11 758 171 316 577 228 44 759 165 110 883 87 566 488 578 475 626 628 630 929 424 521 903 963 124 597 738 262 196 526 265 261 203 117 31 327 12 772 412 548 154 521 791 925 189 764 941 852
//	

