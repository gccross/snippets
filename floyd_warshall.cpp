#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main (int argc, char const * argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int adj[n][n], ans[n][n];
		for (int i=0; i<n; ++i)
		{
			for (int j=0; j<n; ++j)
			{
				cin >> adj[i][j];
				ans[i][j] = adj[i][j];
			}
		}

		int i=0;
		int j=0;
		int dist = 0;
		vector<bool> vis_sub(n, false);
		vector<bool> vis_loop(n, false);
		vector<int> stk;
		for (int i=0; i<n; ++i)
		{
			stk.push_back(i);
			vis_loop[i] = true;
			while (!stk.empty())
			{
				int j = 0;
				while (j<n)
				{
					if (vis_loop[j]==false &&  INT_MAX != adj[i][j]) 
					{
						vis_loop[j] = true;
						dist += adj[i][j];
						ans[stk.front()][j] = min(ans[stk.front()][j],dist);
						stk.push_back(j);
						i = j;
						j = 0;
					}
					else
					{
						++j;
					}
				}
				dist-=adj[stk.back()][i];
				j = i;
				i = stk.back();
				stk.pop_back();
			}
			vector<bool>(n,false).swap(vis_loop);
		}

		cout << endl;
		for (int i=0; i<n ; ++i)
		{
			for (int j: ans[i])
				cout << j << '\t' ;
			cout << endl;
		}

	}
	return 0;
}
/*
   The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. The Graph is represented as Adjancency Matrix, and the Matrix denotes the weight of the edegs (if it exists) else INF (1e7).

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains an integer V denoting the size of the adjacency matrix. The next V lines contain V space separated values of the matrix (graph). All input will be integer type.

Output:
For each test case output will be V*V space separated integers where the i-jth integer denote the shortest distance of ith vertex from jth vertex. For INT_MAX integers output INF.

Constraints:
1 <= T <= 20
1 <= V <= 100
1 <= graph[][] <= 500

Example:
Input
2
2
0 25
INF 0
3
0 1 43
1 0 6
INF INF 0

Output
0 25
INF 0
0 1 7
1 0 6
INF INF 0


*/
