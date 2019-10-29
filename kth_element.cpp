#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>
#include <queue>
#include <utility>

int main() {
	//code
	size_t T;
	std::cin >> T;
	while (T--) {
	    size_t N, K;
	    std::cin >> N;
	    std::vector<uint32_t> v;
	    std::copy_n(std::istream_iterator<uint32_t>(std::cin), N, std::back_inserter(v));
		std::chrono::time_point<std::chrono::system_clock> t1 = std::chrono::system_clock::now();
		std::make_heap(v.begin(), v.end(), std::greater<uint32_t>());
	    std::cin >> K;
		while (1 != K--) {
			std::pop_heap(v.begin(), v.end(), std::greater<uint32_t>());	
			v.pop_back();
		}
		std::cout <<  v.front() << std::endl;
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
