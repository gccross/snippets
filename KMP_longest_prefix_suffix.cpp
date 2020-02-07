#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (int argc, char const * argv[])
{
	string pattern, text;
	ifstream ifs;
	if (argc == 2) 
	{
		cout << "reading from file: " << argv[1]  << endl;
		ifs.open(argv[1]);	
		if (ifs.fail())
			cout << "couldn't open the file: " << argv[1] << endl;
		else
			cin.rdbuf(ifs.rdbuf());
	} 
	else if (argc == 3)
	{
		cout << "pattern: " << argv[1] << "\t string: " << argv[2] << endl;
		pattern = argv[1];
		text = argv[2];
	}

	if (pattern.empty())
	{
		if (cin.eof())
			cout << "please enter your pattern, then string: " << endl;
		cin >> pattern;
		cin >> text;;
	}

	// first, make the lps array (longest prefix suffix - search it up) 
	vector<int> lps(pattern.length());
	cout << "Going to find longest prefix suffix array on this string: " << pattern << endl;

	{
	int len = 0;
	int i = 1;

	while (i < pattern.length())
	{
		if (pattern[i] == pattern[len])
		{
			++len;
			lps[i] = len;
			++i; 
		}
		else
		{
			if (len == 0)
			{
				lps[i] = 0; // nothing is matching this suffix, set 0 and move on
				++i;
			}
			else
			{
				len = lps[len-1]; // doesn't match suffix, move back to last known extent,  and re-try
			}
		}
	}
	}

	cout << "Dis be ur longest prefix suffix array: {" ;
	copy(lps.begin(), lps.end(), ostream_iterator<int>(cout, ","));
	cout << '}'  << endl;

	// Now, pattern match

	int i = 0, j = 0;
	while (i < text.length())
	{
		if (pattern[j] == text[i])
		{
			++i;
			++j;
		}
		
		if (j == pattern.length())
		{
			cout << "Match found at position " << i - j << endl;
			j = lps[pattern.length() - 1];
		}
		else if (i < text.length() && pattern[j] != text[i])
		{
			if (j != 0)
				j = lps[j-1];
			else 
				++i;
		}
	}
	
	return 0;

}
/* sample input

"ABABCABAB" "ABABDABACDABABCABAB"
*/
