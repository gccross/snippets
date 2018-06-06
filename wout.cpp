#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main () 
{
	vector v{ L'§',L'è', L'é', L'ò', L'ò', L'ò', L'ù', L'ﬁ', L'Æ', L'Æ'};

	copy (v.begin(), unique(v.begin(), v.end()), ostream_iterator<wchar_t, wchar_t>(wcout, L" "));
	cout << endl;
	return 0;
}

