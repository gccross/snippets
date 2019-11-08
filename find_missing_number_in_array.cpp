#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

template <typename It>
int find_missing(It first, It last)
{
	int len = distance(first,last);
	if (1 == len) return *first + 1;

	It mid = first + len / 2;
	if (*mid  - *first != len/2)
		return find_missing(first, first + len/2);
	else 
		return find_missing(first + len/2, last);

	
}

int main() {
	//code
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		--N;
		int a[N];
		copy_n(istream_iterator<int>(cin), N, a);
		sort(a, a+N);
		int missing = *a == 2 ? 1 : find_missing(a, a+N);
		cout <<  missing << endl;
	}
	return 0;
}
