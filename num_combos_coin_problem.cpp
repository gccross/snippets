#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main (int argc, char const * argv[])
{
	size_t T;
	cin >> T;
	while (T--){
		size_t N, V;
		cin >> N;
		uint16_t a[N];
		copy_n(istream_iterator<uint16_t>(cin), N, a);
		cin >> V;
		size_t dp[V+1];
		fill(dp, dp+V+1, 0);
		dp[0] = 1;
		for (int i=0; i<N; ++i)
			for (int j=a[i]; j<V+1; ++j)
				dp[j] = dp[j] + dp[j - a[i]]; 

		cout << dp[V] << endl;
	}
	return 0;

}
