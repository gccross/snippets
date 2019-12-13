#include <deque>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {
    int nrows = matrix.size();
    int ncols = matrix[0].size();
    vector<vector<int>> memo(nrows+2, vector<int>(ncols+2,0));
    vector<vector<int>> m2(nrows+2, vector<int>(ncols+2,0));
    for (int i=1; i<nrows+1; ++i)
        for (int j=1; j<ncols+1; ++j)
            m2[i][j] = matrix[i-1][j-1];

    int max_count = 0;
    for (int i=0; i<nrows+1; ++i)
        for (int j=0; j<ncols+1; ++j)
            if (m2[i][j] == 1 && memo[i][j] == 0)
            {
                int count = 0;
                deque<pair<int,int>> todo{{i,j}};
                while (!todo.empty())
                {
                    pair<int,int> p = todo.front();
                    todo.pop_front();
                    for (int dx=-1; dx <= 1; dx++)
                        for (int dy=-1; dy <= 1; dy++)
                            if (m2[p.first+dx][p.second+dy] == 1 && 
                                memo[p.first+dx][p.second+dy] == 0)
                            {
                                ++count;
                                memo[p.first+dx][p.second+dy] = 1;
                                todo.emplace_back(make_pair(p.first+dx,p.second+dy));
                            }
                }
                max_count = max(max_count, count);
            }
    return max_count;
}

int main()
{

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    cout << result << "\n";

    return 0;
}

