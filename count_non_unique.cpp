#include <algorithm> 
#include <iostream>
#include <fstream>

using namespace std;


template <typename It>
int count_unique(It first, It last)
{
	sort(first, last);
	It it = adjacent_find(first, last);
	size_t count {0};
	while (it != last) {
		typename It::value_type val = *it;
		count += distance(first, it);
		while (it!= last && val == *it) ++it;
		first = it;
		it = adjacent_find(first, last);
	}
	count += distance(first, it);
	return count;
	
}

int main (int argc, char const * const  argv[])
{
	ifstream ifs;
	if (1 < argc) {
		ifs.open(argv[1]);
		cin.rdbuf(ifs.rdbuf());
	}
	
	string line;
	while (getline(cin, line)) {
		cout << count_unique(line.begin(), line.end()) << endl;	 
	}
	return 0;

}
