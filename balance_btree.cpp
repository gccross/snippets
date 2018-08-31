// for dbopen, btree
#include <sys/types.h>
#include <db.h>
#include <fcntl.h>
#include <limits.h>

#include <libgen.h>

#include <iostream> 
#include <iterator>

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
	size_t front(s.rfind("/")+1);
	size_t back(s.rfind("."));
	return s.substr(front, back-front);
}

int main (int argc, char * const argv[])
{
	string filename(basename(__FILE__));
	
	diag(filename);
	
	dbopen((filename+".db").c_str(),   O_CREAT|O_RDWR, S_IRWXG|S_IRWXU|S_IRWXO, DB_BTREE, NULL);
	return 0;
}
