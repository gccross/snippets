#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

// You are given a sequence of integers where every value but one occurs twice at random places.  
// Find which is that unique value.
//
// eg. (spoiler alert, this is the answer): 
//
// [2, 1, 1, 2, 3] => 2*2 + 2*1 + 1*3 => 9
// {2, 1, 3} => 2*2 + 2*1 + 2*3 => 12

template <typename InputIt>
InputIt find_single(InputIt beg, InputIt end)
{
	typedef typename iterator_traits<InputIt>::value_type T;
	unordered_set<T> s{beg, end};
	
	T sum1{accumulate(beg, end, 0)};
	T sum2{accumulate(s.begin(), s.end(), 0)};

	return find(beg, end, 2*sum2 - sum1);
}


int main()
{
	int x[]{ 87, 89, 88, 87, 88, 89, 42, 48, 49, 49, 42, 48, 5 };
	size_t x_len = sizeof(x)/sizeof(x[0]);
	vector<int> v(x,x+x_len);
	int* it1;

	if ((it1=find_single(x, x+x_len))!=x+x_len) 
		cout << *it1 << endl;
	
	vector<int>::iterator it2;
	if ((it2=find_single(v.begin(), v.end()))!=v.end()) 
		cout << *it2 << endl;
	return 0;
}

