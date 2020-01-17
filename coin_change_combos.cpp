#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(const int argc, char const * const argv[])
{
	int T;
	cin >> T;
	while (T--)
	{
		int m;
		cin >> m;
		vector<int> a(m);
		copy_n(istream_iterator<int>(cin), m, a.begin());
		int n;
		cin >> n;
		vector<int> dp(n+1,0);
		dp[0] = 1;
		for (int i = 0; i<m ; ++i)
			for (int j = a[i]; j < n+1; ++j)
				dp[j] += dp[j - a[i]];

		cout << dp[n] << endl;

	}
	return 0;

}
