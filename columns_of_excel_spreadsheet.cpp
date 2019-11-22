#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const * const argv[]) {
	//code
	int T;
	cin >> T;
	while (T--){
        int N;
	    cin >> N;
	    string s;
		size_t i=N;
		while (i) {
			s.push_back(--i%26 + 'A');
			i/=26;
		}
		copy(s.rbegin(), s.rend(), ostream_iterator<char>(cout, ""));
	    cout << endl;
	}
	return 0;
}
