#include <chrono>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

int main (int argc, char const * argv[])
{
	int T;
	cin >> T;
	chrono::time_point<chrono::system_clock> t1 = chrono::system_clock::now();
	while (T--)
	{
		int N;
		cin >> N;
		if (N < 2) { cout << 0 << endl; continue; }

		int more_can_skip = N/2 + N%2;

		vector<bool> dp(N,false);
		vector<int> a;
		copy_n(istream_iterator<int>(cin), N, back_inserter(a));

		int res = accumulate(a.begin(), a.end(), 0);
		priority_queue<int> pq(a.begin(), a.end());
		while (more_can_skip)
		{
			int x = pq.top();	
			vector<int>::iterator it = find(a.begin(), a.end(), x);

			while (it!= a.end())
			{
				size_t d = distance(a.begin(), it);
				if ((d == 0 && dp[1] == false) 
					|| 
					(d == N-1 && dp[N-2] == false)
					||
					(dp[d-1] == false && dp[d+1] == false))
				{
					dp[d] = true;
					res -= a[d];
					--more_can_skip;
				}
				++it;
				it = find(it,a.end(),x);
			}	
			pq.pop();
		}

		cout << res << endl;
		


	}
	cout << (chrono::system_clock::now() - t1).count() << endl;
	return 0;

}
