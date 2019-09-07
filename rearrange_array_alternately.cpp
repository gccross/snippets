#include <iterator>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	//code

	size_t T, N;
	cin >> T;
	while (T--) {

		cin >> N;
		vector<string> v(N);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string line;
		getline(cin,line);
		istringstream is(line);
		vector<string>::iterator it = v.begin();
		while (is && it!=v.end()) is >> *it++;

		// now rearrange, alternate
		it = v.begin();
		vector<string>::reverse_iterator rit = v.rbegin();
		while (it < rit.base()) {
			*it += string("|") + *rit; 
			++it; ++rit;
		}

		// annoyance trying to compare reverse iterators and iterators
		vector<string>::reverse_iterator rit2 = v.rbegin();
		if (N%2) {
			--it;	
			*rit2++ = it->substr(it->find('|')+1); 
		}

		while (rit != v.rend()) {
			*rit2 = rit->substr(0,rit->rfind('|'));
			++rit2;
			*rit2 = rit->substr(rit->find('|')+1);
			++rit; ++rit2;
			
		}

		for (string i: v) cout << i << ' ';
		cout << endl;
	}
	return 0;
}
