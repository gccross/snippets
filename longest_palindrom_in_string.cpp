#include <iterator>
#include <iostream>
#include <utility>
using namespace std;

int main(int const argc, char const * const argv[]) {
	size_t T;
	cin >> T;
	while (T--) {
	    string s;
	    cin >> s;
	    pair<string::iterator, string::iterator> palindrom;
	    size_t len{0};
		
        string::iterator it=s.begin(); 
		while (it < s.end()) {
            string::iterator left {it}, right {it};
            while (right < s.end() && *left == *++right);
            while (left > s.begin() && right < s.end() && *(left-1) == *(right)) { --left; ++right; }
            size_t len_new = distance(left,right);
            if (len < len_new) {
                palindrom = make_pair(left,right);
                len = len_new;
            }
			++it;
        }
        copy(palindrom.first, palindrom.second, ostream_iterator<char>(cout, ""));
        cout << endl;
	}
	return 0;
}
