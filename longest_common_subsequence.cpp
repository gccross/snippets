#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(const int argc, const char * const argv[]) {
    int T;
    cin >> T;
    while (T--)
    {
            int m,n;
            cin >> m >> n;
            
            vector<char> left(m,0), right(n,0);
            copy_n(istream_iterator<char>(cin), m, left.begin());
            copy_n(istream_iterator<char>(cin), n, right.begin());
			int rows = m+1, cols = n+1;
            vector<int> dp = vector<int>(rows * cols, 0);
            
            for (int i = 1; i < rows; ++i)
                for (int j = 1; j < cols; ++j)
                {
                    if (left[i-1] == right[j-1])
                        dp[i*cols + j] = dp[(i-1)*cols + j-1] + 1;
                    else
                        dp[i*cols + j] = max(dp[i*cols + j - 1], dp[(i-1)*cols + j]);
                    cout << "left: " << left[i-1] << " right: " << right[j-1] << " " << "dp[" << i*cols+j << "] = " << dp[i*cols+j] << endl;
                }
                
            cout <<  dp[rows*cols-1] << endl;

    }//code
	return 0;
}

