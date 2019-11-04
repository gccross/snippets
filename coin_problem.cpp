#include<iostream>
#include<algorithm>
#include<climits>


using namespace std;


int main(){
	int t;
	cin >> t;
	while(t--){
		int v, n;
		cin >> v >> n;

		int coin[n];

		for(int i = 0; i < n; i++) cin >> coin[i];

		int dp[v+1];

		for(int k = 0; k < v+1; k++) dp[k] = {INT_MAX};
		dp[0] = 0;

		for(int i = 0; i < n; i++){
			for(int j = coin[i]; j < v+1; j++){
				if(dp[j-coin[i]] != INT_MAX && dp[j] > dp[j-coin[i]]+1) 
					dp[j] = dp[j-coin[i]] + 1;
			}
		}

		if(dp[v] == INT_MAX) cout << -1 << endl;
		else cout << dp[v] << endl;
	}
	return 0;
}
//	Given a value V. You have to make change for V cents, given that you have infinite supply of each of 
//	C{ C1, C2, .. , Cm} valued coins.  	Find the minimum number of coins to make the change.
//	
//	Input:
//	The first line of input contains an integer T denoting the number of test cases. 
//	The first line of each test case is V and N, V is the value of cents and N is the number of coins. 
//	The second line of each test case contains N input C[i], value of available coins.
//	
//	Output:
//	Print the minimum number of coins to make the change, if not possible print "-1".
//	
//	Constraints:
//	1 ≤ T ≤ 100
//	1 ≤ V ≤ 106
//	1 ≤ N ≤ 106
//	1 ≤ C[i] ≤ 106
//	
//	Example:
//	Input:
//	1
//	7 2
//	2 1
//	
//	Output:
//	4
//	
//	Explanation :
//	Testcase 1: We can use coin with value 2 three times, and coin with value 1 one times to change a total of 7.
//	
//	
//	Input:
//	7685 27
//	55 38 85 57 69 90 70 98 20 66 17 43 94 96 68 93 84 74 37 97 11 71 73 39 54 83 82
//	
//	Its Correct output is:
//	79
//	
//	And Your Code's output is:
//	80
//	
//	Input:
//	8777 5
//	86 7 43 67 6
//	
//	Its Correct output is:
//	103
//	
//	And Your Code's output is:
//	102
//	
