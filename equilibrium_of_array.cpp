#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

template <typename It>
int find_equilibrium(It first, It last)
{
	size_t ret = 0;
	It it{first};
	
	// we're guaranteed distance(first, last) is at least 1

	// first edge case, only 1 element
	if (1 == distance(first, last)) return 1;	

	++it;
	double left_sum = 0, right_sum = reduce(it,last);

	// second edge case, sum(v[1]...v[n]) == 0, so v[0] is equilibrium
	if (0 == right_sum) return 1; 

	It it_prev = first;
	while (it != last && left_sum != right_sum) {
		left_sum += *it_prev;
		right_sum -= *it;
		++it;
		++it_prev;
	}

	if (it == last) ret=-1;
	else ret = distance(first, it);
	return ret;
}

int main (int argc, char const * const argv[])
{
	ifstream ifs;
	if (1 < argc) {
		ifs.open(argv[1]);
		cin.rdbuf(ifs.rdbuf());
	}
	
	size_t T=0;
	cin >> T;
	while (T--) {
		size_t N;
		cin >> N;
		vector<uint32_t> v(N);	
		copy_n(istream_iterator<uint32_t>(cin), N, v.begin());
		cout << find_equilibrium(v.begin(), v.end()) << endl;
	}
	return 0;
}
//	
//	Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
//	
//	Input:
//	The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A.
//	
//	Output:
//	For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.
//	
//	Constraints:
//	1 <= T <= 100
//	1 <= N <= 106
//	1 <= Ai <= 108
//	
//	Example:
//	Input:
//	2
//	1
//	1
//	5
//	1 3 5 2 2
//	
//	Output:
//	1
//	3
//	
//	Explanation:
//	Testcase 1: Since its the only element hence its the only equilibrium point.
//	Testcase 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements after it (2+2).
//	 
//	
//	
//	2
//	17
//	27 4 25 6 6 1 27 22 19 29 6 9 36 24 6 15 5 
//	8
//	43 34 2 8 17 5 11 8
//	Your Output is:
//	-1
//	-1
