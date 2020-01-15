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

/*
Given two strings S and T, find count of distinct occurrences of T in S as a sub-sequence. Your task is to complete the function subsequenceCount which takes two strings as argument S and T and returns the count of the sub-sequences.

Input:
The first line of input contains an integer t denoting the no of test cases . Then t test cases follow. The first line of each test case contains 2 strings S and T.

Output:
For each test case in a new line print the count of distinct occurrences of T in S as a sub-sequence.

Constraints:
1<=t<=100
1<=length of (S,T)<=100

Example(To be used only for expected output):
Input
2
banana ban
geeksforgeeks ge

Output
3
6

Explanation:
(i) For first test case  S = banana, T = ban there are 3 sub-sequences which are [ban], [ba n], [b an].
(ii) For second test case S = geeksforgeeks, T=ge there are 6 sub-sequences which are  [ge], [ ge], [g e], [g e] [g e] and [ g e].

*/
