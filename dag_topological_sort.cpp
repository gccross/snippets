#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    int indegree[V]; memset (indegree, 0 , sizeof(indegree));
    for (int i=0; i<V; ++i)
    {
        for (int j: adj[i])
            ++indegree[j]; 
    }
    vector<int> res;
    deque<int> dq;
    for (int i=0; i<V; ++i)
    {
        if (indegree[i] == 0)
        {
            dq.push_back(i);
        }
    }
    while (!dq.empty())
    {
        int node = dq.front();
        dq.pop_front();
        res.push_back(node);
        
        for (int j: adj[node])
        {
            if (--indegree[j] == 0)
            {
                dq.push_back(j);
            }
        }
    }
    return res;
}

