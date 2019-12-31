#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--)
	{
	    int N;
	    cin >> N;
	    vector<int> dp(N+1,0);
	    dp[0] = 1;
	    vector<int> steps{ 1, 2 };
	    for (int i = 0; i< steps.size(); ++i)
	    {
    	    for (int j = i; j < N+1; ++j)
    	    {
    	            dp[j] += dp[j - steps[i]];
    	    }
	    }
	    cout << dp[N] << endl;
	}
	return 0;
}
