#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <utility>


template <typename It>
It partition(const It first,const It last)
{
	It left=first+1, right=last-1, mid=first;
	std::advance(mid, std::distance(first, last)/2);
	typename It::value_type pivot = *mid;
	std::swap(*first, *mid);

	while (left <= right)
	{
		while(left <= right && *left <= pivot) ++left;
		while(left <= right && *right > pivot) --right;

		if (left < right) std::swap(*left, *right);


	}
	--left;
	std::swap(*left, *first);
	return left;

}
template <typename It>
void quicksort(It first, It last)
{
	if (first >= last) return;

	It mid = partition(first, last);

	quicksort(first, mid);
	quicksort(mid+1, last);

}

int main(int argc, const char * const argv[])
{
	std::ifstream ifs;
	if (1<argc) {
		ifs.open(argv[1]);
		std::cin.rdbuf(ifs.rdbuf());
	}

	std::vector<std::string> v;
	std::copy(std::istream_iterator<std::string>(std::cin),std::istream_iterator<std::string>(), std::back_inserter(v));
	quicksort(v.begin(), v.end());
	for (std::string s: v) std::cout << s;
	std::cout << std::endl;
	return 0;
}
