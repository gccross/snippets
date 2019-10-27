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

