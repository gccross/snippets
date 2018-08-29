#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

// You are given a sequence of integers where every value but one occurs twice at random places.  
// Find which is that unique value.
//
// eg. (spoiler alert, this is the answer): 
//
// [2, 1, 1, 2, 3] => 2*2 + 2*1 + 1*3 => 9
// {2, 1, 3} => 2*2 + 2*1 + 2*3 => 12

template <typename InputIt, typename T=typename InputIt::value_type>
InputIt find_single(InputIt beg, InputIt end)
{
	set<T> s;
	for (InputIt it=beg; ++it!=end;)
	{
		s.insert(*it);
	}

	T sum1{accumulate(beg, end, 0)};
	T sum2{accumulate(s.begin(), s.end(), 0)};

	return find(beg, end, 2*sum2 - sum1);
}

template <typename T>
T* find_single(T* beg, T* end)
{
	return find_single<T*, T>(beg, end);
}

int main()
{
	int x[]{ 87, 89, 88, 87, 88, 89, 42, 48, 49, 49, 42, 48, 5 };
	vector<int> v(x,x+sizeof(x)/sizeof(x[0]));
	cout << *(find_single(v.begin(), v.end())) << endl;
	cout << *(find_single(x, x+sizeof(x)/sizeof(x[0]))) << endl;
	return 0;
}

