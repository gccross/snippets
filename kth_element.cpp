#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <utility>

namespace george {

template <typename It>
It partition(It first, It last)
{
	It left = first+1, right = last - 1;
	It pivot = first;
	while (left <= right)
	{
		while (left <= right && *left <= *pivot) ++left;
		while (left <= right && *right > *pivot) --right;

		if (left < right) std::swap (*left, *right);

	}
	--left;
	std::swap (*pivot, *left);
	return left;
}

template <typename It>
void nth_element(It first, It nth, It last)
{
	if (first >= last) return;
	It mid = partition(first, last);

	if (mid == nth)
		return;

	if (mid <= nth)
		george::nth_element(mid+1, nth, last);
	else 
		george::nth_element(first, nth, mid);
	
	
}

} // namespace 

int main() {
	//code
	size_t T;
	std::cin >> T;
	while (T--) {
	    size_t N, K;
	    std::cin >> N;
	    std::vector<uint16_t> v;
	    std::copy_n(std::istream_iterator<uint16_t>(std::cin), N, std::back_inserter(v));
	    std::cin >> K;
		george::nth_element(v.begin(), v.begin() + K - 1, v.end());
	    std::cout << *(v.begin() +K -1)  << std::endl;
	}
	return 0;
}
//	
//	Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
//	
//	Expected Time Complexity: O(n)
//	
//	Input:
//	The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.
//	
//	Output:
//	Corresponding to each test case, print the kth smallest element in a new line.
//	
//	Constraints:
//	1 <= T <= 100
//	1 <= N <= 105
//	1 <= arr[i] <= 105
//	1 <= K <= N
//	
//	Example:
//	Input:
//	2
//	6
//	7 10 4 3 20 15
//	3
//	5
//	7 10 4 20 15
//	4
//	
//	Output:
//	7
//	15
//	
//	Explanation:
//	Testcase 1: 3rd smallest element in the given array is 7.
//	
//	
//	
