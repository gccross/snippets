#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char const * argv[])
{
	int T;
	cin >> T;
	while (T--)
	{
		int cows = 0, bulls = 0;
		string a,b;
		cin >> a >> b;
		//vector<reference_wrapper<char>> bs (b.begin(), b.end());
		//sort(bs.begin(), bs.end());
		// why reference_wrapper if just chars???
		string bsorted = b;
		sort(bsorted.begin(), bsorted.end());
		cout << b << endl;

		for (int i = 0; i<a.size(); ++i)
		{
			if (a[i] == b[i]) ++bulls;
			if (binary_search(bsorted.begin(),bsorted.end(), a[i])) ++cows;
		}
		copy(bsorted.begin(),bsorted.end(), ostream_iterator<char>(cout, ""));
		cout << endl;

		cout << "Cows: " << cows << " Bulls: " << bulls << endl;
	}
	return 0;

}
