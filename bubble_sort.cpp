#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

// bubble sort, and calculating paths in a 2-D matrix

typedef vector<int>::pointer itv;
typedef vector<int>::value_type itt;     

template <typename FwdIter>
FwdIter bubble_sort(FwdIter begin, FwdIter end)
{
	for (FwdIter i=begin; i!=end; ++i)
	{
		for (FwdIter j=i; j!=end; ++j)
		{
			if (*i>*j)
			{
				itt temp = *i;
				*i = *j;
				*j = temp;
			}
		}
	}
	return begin;
}

size_t calculate_paths(size_t rows, size_t columns)
{
	if (1 >= rows ||  1 >= columns ) 
		return 1;
	return calculate_paths(rows -1, columns) + calculate_paths(rows, columns -1);
}

int main()
{
	int x[]{68,43,2,39,90,55};
	vector<int>  mysequence {3,46,43,98,27};
	bubble_sort(mysequence.begin(),mysequence.end());
	copy(mysequence.begin(), mysequence.end(), ostream_iterator<int>(cout, " "));
	auto f([](){cout << endl; });
	f();
	copy(bubble_sort(x, x+sizeof(x)/sizeof(x[0])), x+sizeof(x)/sizeof(x[0]), ostream_iterator<int>(cout, " "));
	f();

	for (size_t i=0; ++i < 8; ) 
		for (size_t j=0; ++j < 8; ) 
			cout << i << " rows, " << j << " columns: " << calculate_paths(i,j) << endl;
	return 0;
}
