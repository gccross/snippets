#include <list>
#include <iterator>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

int main() {
	//code

	size_t T, N;
	cin >> T;
	while (T--) {

		cin >> N;
		list<unsigned> v(N);
		list<unsigned>::iterator it = v.begin();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string line;
		getline(cin,line);
		istringstream is(line);
		while (is && it!=v.end()) is >> *it++;

		// now rearrange, alternate
		unsigned marker = v.back(), num_loops=0;
		while (marker != v.front()) {  
			v.push_back(v.front());
			v.pop_front();
			if (marker != v.front()) {
				list<unsigned>::iterator it = find(v.begin(), v.end(), marker); 
				--it; 
				v.push_back(*it);
				v.erase(it);
			}
		}

		
		for (unsigned i: v) cout << i << ' ';
		cout << endl;
	}
	return 0;
}
