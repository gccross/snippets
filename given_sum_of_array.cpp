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
		uint32_t sum{0};
		int i=0, left = 0, right=0;
		
		while (i < N) {
			cin >> a[i];
			sum += a[i];
			while (sum > S) sum -= a[left++];

			if (sum == S) {
				cout << left+1 << " " << i+1 << endl;
				break;
			}
			++i;
		}

		if (sum != S) cout << -1 << endl;

	}
	return 0;
}
