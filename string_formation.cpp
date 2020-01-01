#include <iostream>
using namespace std;

int main(int argc, char const * const argv[] 
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> 	s;
			source += s;
		}

		string target;
		cin >> target;

		int ans = 0;
	
		for(char c: target)
		{
			size_t pos = s.find_first_of(c);
			if (pos == npos) continue;
			pos = s.find_first_of(
		}



		


	}
	
	return 0;
}

/* 
	From HCL test.
	Given a vector of strings all the same length, make a target string using elements 
	from the vector of strings, such that the source index of elements is strictly increasing 
	in order of their deployment to the target string.
	Sample input: abc, aec, efg, and target string a,c
	Output: ac, ac, ca, ac
*/
