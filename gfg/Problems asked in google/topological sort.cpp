/*
https://practice.geeksforgeeks.org/problems/topological-sort/1#
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

vector<int>in;

vector<int> kahn(vector<int>adj[],int V){
    queue<int>q;
    for(int i=0;i<V;i++)
    if(in[i]==0)
    q.push(i);
    
    vector<int>sol;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        sol.push_back(cur);
        for(auto to:adj[cur]){
            in[to]--;
            if(in[to]==0)
            q.push(to);
        }
    }
    
    return sol;
}

class Solution{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    in.assign(V+1,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){in[x]++;}
	    }
	    return kahn(adj,V);
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

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
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends