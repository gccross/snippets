#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

int main (int argc, char const * argv[])
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<> dist(-20, 20);

	vector<int> v;
	generate_n(back_inserter(v),100, bind(dist,mt));
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	
	rotate(v.begin(), v.end(), v.end());
	cout << endl << "Hello World " __FILE__ << endl << endl;; 

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout.flush();

	// dangerous, should check it == last.
	vector<int>::iterator it = rotate(v.begin(), v.begin(), v.end());
	cout << "Index: " << distance(v.begin(), it) << " Value: " << *it << endl;
	
	return 0;

}
