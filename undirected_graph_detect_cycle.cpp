#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
using namespace std;

enum phase { white, gray, black };
bool recurse(vector<int> g[], int V, int node, phase visited[], int parent);
bool isCyclic(int V, vector<int> g[])
{
   // Your code here
   phase visited[V]; memset(visited,white,sizeof(visited));
   for (int i=0; i<V; ++i)
   {
        if (visited[i] == white)
            if (recurse(g,V,i,visited, -1)) 
                return true;
   }
   return false;
}

bool recurse(vector<int> g[], int V, int node, phase visited[], int parent)
{
    visited[node] = gray;
	bool parent_checked = false;
            
    for (int j=0; j<g[node].size(); ++j)
    {

        if (!parent_checked && j==parent)
		{
			parent_checked = true;
            continue;
		}
        if (visited[g[node][j]] == gray)
		{
            return true;
		}
        if (visited[g[node][j]] == white) 
        {
            if (recurse(g,V,g[node][j], visited, node))
                return true;
        }
    }
    visited[node] = black ;
    return false;
}

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
	        adj[v].push_back(u);

	    }
	    
		chrono::time_point<chrono::system_clock> t1 = chrono::system_clock::now();
	    cout << isCyclic(v, adj) << endl;
		cout << "executed in: " << (chrono::system_clock::now() - t1).count() << " milliseconds" << endl;

		/*
		chrono::time_point<chrono::system_clock> t3 = chrono::system_clock::now();
		cout << isCyclic_topological_sort(v,adj) << endl;
		cout << "topo sort executed in: " << (chrono::system_clock::now() - t3).count() << " milliseconds" << endl;;
		*/
	    
	}
	
	return 0;
}  // } Driver Code Ends
