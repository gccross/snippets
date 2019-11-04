#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits>
using namespace std;

int main() {
	size_t T;
	cin >> T;
	while (T--)
	{
		size_t N;
		cin >> N;
		int32_t a[N];
		int64_t maxx = numeric_limits<int64_t>::min();
		int64_t maxx2 = numeric_limits<int64_t>::min();
		int64_t maxx3 = numeric_limits<int64_t>::min();
		int64_t minn = numeric_limits<int64_t>::max();
		int64_t minn2 = numeric_limits<int64_t>::max();

		copy_n(istream_iterator<int32_t>(cin), N, a);
		make_heap(a, a+N);
		maxx = a[0];
		pop_heap(a, a+N);
		maxx2 = a[0];
		pop_heap(a, a+N-1);
		maxx3 = a[0];

		make_heap(a, a+N, greater<int64_t>());
		minn = a[0];
		pop_heap(a, a+N, greater<int64_t>());
		minn2 = a[0];

		int64_t collective_max = max(minn*minn2*maxx,maxx*maxx2*maxx3) ;
		cout << collective_max << endl;      
	}
	return 0;
}
