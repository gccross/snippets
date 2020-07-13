#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool isCyclic(int V, vector<int> adj[])
{
#ifdef DEBUG
	for (int i=0; i<V; ++i)
	{
		cout << i << ":\t" ;
		copy (adj[i].begin(), adj[i].end(), ostream_iterator<int>(cout, "\t"));
		cout << endl;
	}
#endif	

	bool vis_origin[V]; memset(vis_origin,false,sizeof(vis_origin));

	for (int i=0; i<V ; ++i)
	{
		if (adj[i].empty() || vis_origin[i]) continue;


		stack<pair<int,int>> stk;
		stk.push(make_pair(i,0));


		while (!stk.empty())
		{
			int node = stk.top().first; 
			int child_index = stk.top().second;
			int child = adj[node][child_index];

			stk.pop();
			if (++child_index < adj[node].size())
				stk.push(make_pair(node,child_index));
			else
				vis_origin[node] = true;

			bool vis[V]; memset(vis,false,sizeof(vis));
			vis[node] = true;

#ifdef DEBUG
			cout << "node: " << node << "\tchild: " << child << endl;
#endif

			while (!adj[child].empty())
			{
				node = child;
				child_index = 0;
				if (vis[node]) 
					return true;
				if (vis_origin[node]) break;
				vis[node] = true;

				stk.push(make_pair(node,child_index));
				child = adj[node][child_index];
			}
		}
	}
	return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
		chrono::time_point<chrono::system_clock> t1 = chrono::system_clock::now();
	    cout << isCyclic(v, adj) << endl;
		cout << "executed in: " << (chrono::system_clock::now() - t1).count() << " milliseconds" << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
/*
Given a Directed Graph. Check whether it contains any cycle or not.

Input: The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'M'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is an uni-directed  edge from u to v .

Output:
The method should return 1 if there is a cycle else it should return 0.

User task:
You don't need to read input or print anything. Your task is to complete the function isCyclic which takes the Graph and the number of vertices and inputs and returns true if the given directed graph contains a cycle. Else, it returns false.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 1000
1<= N,M <= 1000
0 <= u,v <= N-1

Example:
Input:
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2
Output:
1
0
1

Explanation:
Testcase 1: In the above graph there are 2 vertices. The edges are as such among the vertices.

61 34
45 16 54 29 12 41 36 13 9 31 49 52 46 53 22 4 8 11 35 19 11 54 22 47 30 37 42 53 44 47 54 28 4 47 59 19 29 35 32 39 5 23 32 51 17 55 57 25 7 31 46 18 26 8 6 57 45 50 51 30 37 47 60 43 35 59 1 4
*/

/*
   simple notes
   */
#ifdef false

while (!stk.empty())
{
	Node* node = stk.top();
	while (node.left)
	{
		node = node.left;
		stk.push(node);
	}
	cout << node.data;
	while (!node.right)
	{
		stk.pop(); 
		if (stk.empty()) return;
		node = stk.top(); 
		cout << node.data;
	}
	stk.pop();
	stk.push(node.right);

}

#endif
