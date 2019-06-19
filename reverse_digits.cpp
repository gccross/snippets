#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;



int main(int argc, const char* const argv[]){
	//code
	unsigned n_testcases(0);
	cin >> n_testcases;
	while (n_testcases--) {
		string value;
		stringstream reversed;
		cin >> value;
		for (string::reverse_iterator it = value.rbegin(); 
				it != value.rend() ;
				++it)
		{
			reversed << *it;
		}

		unsigned pos(0);
		reversed.seekp(ios::beg);
		while ('0' == reversed.str()[pos]) reversed.seekp(++pos);

		cout << reversed.str().substr(pos) << endl;

		// or we could stream it in
		reversed.seekp(ios::beg);
		reversed >> pos;
		cout << pos << endl;

	}
	return 0;
}
