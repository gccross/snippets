#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int subsequenceCount(string S, string T);
//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		cout<<subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method*/
int subsequenceCount(string S, string T)
{
    size_t m = S.size();
    size_t n = T.size();
    
    if (n == 0) return 1;
    if (m == 0) return 0;
    if (T[T.size()-1] == S[S.size()-1])
        return subsequenceCount(S.substr(0,m-1), T.substr(0,n-1))
            +
            subsequenceCount(S.substr(0,m-1), T);
    else
        return subsequenceCount(S.substr(0,m-1), T);
            
}
 
int subsequenceCount_dp(string S, string T)
{
    size_t m = S.size();
    size_t n = T.size();

	vector<vector<int>> dp{m+1,vector<int>(n+1,0)};
	for (int i=0; i < n+1; ++i)
		dp[0][i] = 0;
	for (int i=0; i < m+1; ++i)
		dp[i][0] = 1;

	for (int i = 1; i < m; ++i)
		for (int j = 1; j < n; ++j)
			if (S[i-1] == T[j-1])
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			else 
				dp[i][j] = dp[i-1][j];

	return dp[m][n];
    
            
}
