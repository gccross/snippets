#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const * const * argv)
{

	{
		string mystring{argv[1]};
		string::size_type pos(0);
		while (string::npos != (pos = mystring.find("  ", pos))){
			mystring.replace(pos, 2,  " "); 
		}
	}

	// but I know you want to see some raw loops
	{
		size_t nchars(strlen(argv[1])), 
			len(nchars+1); // including null terminator
		unique_ptr<char> pcopy(new char[len]);
		copy(argv[1], argv[1]+len, pcopy.get());
		
		size_t pos(0), next_pos(0);
		char* const p = pcopy.get();
		while (next_pos != len) {
			++next_pos;
			if (' ' == p[pos])  while (' ' == p[next_pos]) ++next_pos;
			if (pos+1 < next_pos) p[pos+1] = p[next_pos];	
			++pos;	
		}
	}
	
	return 0;
}
