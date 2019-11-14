#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <utility>

namespace george {

template <typename It>
It partition_hoare(It first, It last)
{
	It left = first+1, right = last - 1;
	while (left <= right)
	{
		while (left <= right && *left <= *first) ++left;
		while (left <= right && *right > *first) --right;

		if (left < right) std::iter_swap (left, right);

	}
	--left;
	std::iter_swap (first, left);
	return left;
}

template <typename It>
It partition_lomuto(It first, It last)
{
	It left = first, right = last - 1;
	while (left < right)
	{
		if (*left < *right)
			std::iter_swap (left, first++);

		++left;
	}
	std::iter_swap (first,left);
	return first;
}

template <typename It>
void nth_element(It first, It nth, It last, It (*partition_function)(It, It))
{
	if (first >= last) return;
	It mid = partition_function(first, last);

	if (mid == nth)
		return;

	if (mid <= nth)
		george::nth_element(mid+1, nth, last, partition_function);
	else 
		george::nth_element(first, nth, mid, partition_function);
	
	
}

} // namespace 

int main() {
	//code
	size_t T;
	std::cin >> T;
	while (T--) {
	    size_t N, K;
	    std::cin >> N;
	    std::vector<std::string> v;
	    std::copy_n(std::istream_iterator<std::string>(std::cin), N, std::back_inserter(v));
	    std::cin >> K;
		std::chrono::time_point<std::chrono::system_clock> t1 = std::chrono::system_clock::now();
		george::nth_element(v.begin(), v.begin() + K - 1, v.end(), george::partition_lomuto);
	    std::cout << *(v.begin() +K -1)  << std::endl;
		std::cout <<  "Duration: " << (std::chrono::system_clock::now() - t1).count() << std::endl;
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
/*
1
12
bin lim kindle spam fram jay brocade kale rambutan flimsy cram parucchio
4
*/
