// count paths from x1,y1 to x2,y2

#include <iostream>
#include <vector>

using namespace std;

unsigned count_paths(vector<vector<unsigned>>& dp, unsigned n, unsigned m){
    if (n==0 || m==0)
        return dp[n][m] = 1;
    if (dp[n][m] == 0) 
        return dp[n][m] = count_paths(dp, n-1, m) + count_paths(dp, n, m-1);
    return dp[n][m];
}
int main(int const argc, char const * const argv[]) {
    size_t T;
    cin >> T;
    while (T--){
        unsigned n,m;
        cin >> n >> m;
        vector<vector<unsigned>> dp (n+1, vector<unsigned>(m+1, 0));
        cout << count_paths(dp,n,m) << endl;
    }
	//code
	return 0;
}

/* 
Sample input: 
1
9 10

Output:
92378

