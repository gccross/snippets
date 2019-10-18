#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>

using namespace std;

template <typename It>
class solver {

public: 

			
	uint64_t solve(It const& first, It const& last)
	{
		if (first == last) return 0L;
		if (1 == distance(first,last)) return *first;

		vector<It> vdb = make_sequence_decreasing_bases(first, last);

		for (It it : vdb) { 

			stack.clear();
			uint64_t seq_sum=0UL, subseq_sum=0UL;

			It base = it, next = it;
			++next;

			subseq_sum = make_sequence_increasing(base, next, last);
			seq_sum = subseq_sum;

			while (stack.size() > 1) {

				//peel off the last element, 
				subseq_sum -= *stack.back();
				next = stack.back();
				stack.pop_back();
				
				// and find a new path forward
				base = stack.back();
				++next;

				subseq_sum += make_sequence_increasing(base, next, last);
				seq_sum = max(seq_sum, subseq_sum);
			}
			max_sum = max(max_sum,seq_sum);
		}		
		return max_sum;
	}

	solver(size_t _N) :max_sum(0),N(_N) { 
	}

private: 

	uint64_t make_sequence_increasing(It base, It next, It const& last) 
	{
		uint64_t sum{0UL};

		if (stack.empty()) {
			sum += *base;
			stack.push_back(base);
		}

		while (next != last) {
			if (*base < *next) {
				sum+=*next;
				stack.push_back(next);
				base=next;
			}
			++next;
		}
		return sum;
	}

	vector<It>  make_sequence_decreasing_bases(It const& first, It const& last)
	{
		vector<It> v;
		It base = first, next = first;
		v.push_back(base);
		while (++next != last) {
			if (*base > *next) {
				v.push_back(next);
				base = next;
			}
		}
		return v;
	}

	uint64_t max_sum;
	size_t N;
	vector<It> stack;
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
		uint32_t a[N];
		for (uint32_t& i: a) cin >> i;
		
		cout <<  solver<uint32_t*>(N).solve(a, a+N) << endl;
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
