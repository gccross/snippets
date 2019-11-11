#include <algorithm> 
#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;


template <typename It>
int count_unique(It first, It last)
{
	unordered_set<typename It::value_type> uos;
	size_t count {0};
	while (first < last)
		if (uos.insert(*first++).second) ++count;
		
		
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
