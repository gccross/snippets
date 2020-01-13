#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

/*
template <typename T>
struct column_iterator : public iterator<forward_iterator_tag, vector<T>>
{
	pointer p;
	iterator(pointer _p): p(_p) {};
	iterator& operator++()
	{
		++p;
		return *this;
	}
	reference operator*()
	{
		return *p;
	}
};
*/

int main(int const argc, const char* const argv[])
{
	int T;
	cin >> T;
	while (T--)
	{
		int M, N;
		cin >> M >> N;
		vector<vector<int>> dp(M+1,vector<int>(N+1,0));

		iota(dp[0].begin(), dp[0].end(), 0);
		int n=0;
		for_each(dp.begin(), dp.end(), [&n](vector<int>& i){ i[0] = n++;});

		string left, right;
		cin >> left >> right;

		for (int i = 1; i<M+1; ++i)
			for (int j = 1; j < N+1; ++j)
			{
				if (left[i-1] == right[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
				{
					dp[i][j] = min(dp[i-1][j]+ 1,dp[i][j-1] + 1);
					dp[i][j] = min(dp[i-1][j-1]+ 1,dp[i][j]);
				}
			}

		for (vector<int>& i: dp)
		{
			for (int j: i)
				cout << j << '\t';
			cout << endl;
		}

		cout << dp[M][N] << endl;
				
	}
	return 0;
}
