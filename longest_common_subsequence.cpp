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
            
			int i;
            for (int k = cols+1; k < rows*cols; ++k)
			{
				i = k/cols; //note: integer div
				int j = k - i*cols; 
				if (j == 0) { ++j; ++k; } 

				if (left[i-1] == right[j-1])
					dp[k] = dp[k - cols - 1] + 1;
				else
					dp[k] = max(dp[k - cols], dp[k - 1]);

				//cout << "k: " << k << " dp[k]: " << dp[k] << " i: " << i << " j: " << j << " left: " << left[i-1] << " right: " << right[j-1] << endl;
			}
                
            cout <<  dp[rows*cols-1] << endl;
    }
	return 0;
}

