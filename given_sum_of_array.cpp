#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, S;
		cin >> N >> S;
		uint32_t a[N];
		copy_n(istream_iterator<uint32_t>(cin), N, a);
		uint32_t sum{0};
		int i=0, j=0;
		
		while (j<=N) {
			while (sum < S) sum+=a[j++];
		
			if (sum == S) {
				cout << i+1 << " " << j << endl;
				break;
			}

			while (sum > S) sum -= a[i++];
		}

		if (sum != S) cout << -1 << endl;

	}
	//code
	return 0;
}
