#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

template <typename It>
int find_missing(It first, It last)
{
	int len = distance(first,last);
	if (1 == len) return *first == 2 ? 1 : *first + 1;

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
		cout <<  find_missing(a, a+N) << endl;
	}
	return 0;
}

// G4G question: a sequence of consecutive ints starting at 1, one of the consecutive sequence is skipped.  Which one is it?
// N = last number in sequence.  N-1 is the count of ints in the sequence.
