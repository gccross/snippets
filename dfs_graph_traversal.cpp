#include <algorithm>
#include <iostream>
#include <functional>
#include <stack>
#include <vector>

using namespace std;
using namespace std::placeholders;


vector<int> recurse(vector<int> const g[], int vertex, bool vis[])
{
	if (vis[vertex]) return {};
	vector<int> res(1, vertex);
	vis[vertex] = true;
	for (int i = 0; i < g[vertex].size(); ++i)
		for (int j: recurse(g, g[vertex][i], vis))
			res.push_back(j);
		
	return res;
}
vector <int> dfs_recurse(vector<int> g[], int N)
{
    if (0 == N) return {};
	bool vis[N];	memset(vis,false, sizeof(vis));	

	return recurse(g, 0, vis);
}

vector<int> dfs(vector<int> g[], int N)
{
	vector<int> res;
	vector<bool> vis(N,false);
	stack<int> stk;
	
	stk.push(0);
	while (!stk.empty())
	{
		int node = stk.top();
		stk.pop();
		if (!vis[node]) 
		{
			res.push_back(node);
			vis[node] = true;
			for (vector<int>::const_reverse_iterator it = g[node].crbegin(); it!= g[node].crend(); ++it)
				stk.push(*it);
		}
	}
	return res;
}

vector<int> bfs(vector<int> g[], int N)
{
	vector<int> res;
	vector<int> vis(N,false);
	deque<int> dq;
	dq.push_back(0);
	while (!dq.empty())
	{
		int node = dq.front();
		dq.pop_front();
		if (!vis[node])
		{
			res.push_back(node);
			vis[node] = true;
			for (vector<int>::const_iterator it = g[node].cbegin(); it != g[node].cend(); ++it)
				dq.push_back(*it);
		}
	}
	return res;
}
// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

		{
        vector <int> res = dfs_recurse(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;
		}
		{
        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;
		}
		{
        vector <int> res = bfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;
		}

    }
	return 0;
}
/*
   Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'E'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v .

Output:
For each testcase, print the nodes while doing DFS starting from node 0.

Your task:
You don't need to read input or print anything. Your task is to complete the function dfs() which takes the Graph and the number of vertices as inputs and returns a list containing the DFS Traversal of the graph starting from the 0th node.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2
Graph doesn't contain multiple edges and self loops.

Example:
Input:
2
5 4
0 1 0 2 0 3 2 4
4 3
0 1 1 2 0 3

Output:
0 1 2 4 3
0 1 2 3

Explanation:
Testcase 1:
0 is connected to 1 , 2 , 3
1 is connected to 0
2 is connected to 0 and 4
3 is connected to 0
4 is connected to 2
so starting from 0 , dfs will be 0 1 2 4 3.
*/
