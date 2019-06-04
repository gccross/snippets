// for dbopen, btree
#include <sys/types.h>
#include <db.h>
#include <fcntl.h>
#include <limits.h>

#include <libgen.h>

#include <algorithm>
#include <iostream> 
#include <iterator>
#include <vector>

using namespace std;

template <typename InputIt>
InputIt balance_tree(InputIt it)
{
	// discover dimensions
	typedef typename iterator_traits<InputIt>::value_type T;
	return it;
}

template <typename T> 
void diag(const T& arg) {  cout << arg << "\n"; };

string basename(const string& in)
{
	string s(in);
	size_t front(s.rfind("/")+1); // npos+1 == 0 magically.  probabaly not portable
	size_t back(s.rfind("."));
	return s.substr(front, back-front);
}

int main (int argc, char * const argv[])
{
	// create something to work with
	open((basename(__FILE__)+".db").c_str(), O_CREAT|O_RDWR, S_IRWXG|S_IRWXU|S_IRWXO, DB_BTREE, NULL);
	vector<int> v(-4,8);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}
