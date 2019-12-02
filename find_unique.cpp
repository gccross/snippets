#include <algorithm>
#include <iostream>
#include <iterator>
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

// just testing my memory of std::unique implementation
template <typename It>
It my_unique(It first, It last)
{
		if (first == last) return last;
		It pred {first};
		while (++first != last) {
			if (*pred != *first)
				*++pred = *first;
		}
		return ++pred;
}

int main()
{
	int x[]{ 87, 89, 88, 87, 88, 89, 42, 48, 49, 49, 42, 48, 5 };
	size_t x_len = sizeof(x)/sizeof(x[0]);

	int sum1 = accumulate(x, x+x_len, 0);
	unordered_set<int> uos{x, x+x_len};
	int sum2 = accumulate(uos.begin(), uos.end(), 0);
	cout << 2*sum2 - sum1 << endl;

	// test of my_unique, 
	sort(x,x+x_len);
	int* it = my_unique(x, x+x_len);
	copy(x,it, ostream_iterator<int>(cout, " "));
	cout << endl;
	vector<string> v{ "กิน", "กิน", "ข้าว", "ข้าว", "ยัง", "กง", "คุณ", "ข้าว", "กง", "กง", "จะ", "ไป", "ไหน","ไหน"};
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " " ));
	cout << endl;
	vector<string>::iterator it2 = my_unique(v.begin(), v.end());
	copy(v.begin(), it2, ostream_iterator<string>(cout, " "));
	cout  << endl;

	v = vector<string>{ "foo" , "bar", "goo", "jar", "bin", "zoo", "camel", "kalamazoo", "jar", "bar", "zoo"};
	sort(v.begin(), v.end());
	vector<string>::iterator it3 = my_unique(v.begin(), v.end());
	copy(v.begin(), it3, ostream_iterator<string>(cout, " "));
	cout << endl;

	return 0;
}

