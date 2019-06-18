#include <iostream>
using namespace std;

int main() {
	unsigned long long value(0);
	unsigned int n_testcases(0);
	cin >> n_testcases;
	while (0 < n_testcases--) {
		unsigned int bits_on(0);
		while (value && 1 >= bits_on ) {
			if (value&1) ++bits_on;
			value >>= 1;
		}
		cout << ( 1 == bits_on  && 0 == value?  "YES" :  "NO" ) << endl;
	}
	return 0;
}
