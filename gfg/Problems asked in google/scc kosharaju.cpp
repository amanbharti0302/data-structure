/*https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


vector<int>trans[6000];
vector<bool>visited;
vector<int>order;


void dfs1(vector<int>adj[],int src){
    visited[src]=true;
    for(auto to:adj[src]){
        if(!visited[to])
        dfs1(adj,to);
    }
    order.push_back(src);
}

void dfs2(int src){
    visited[src]=true;
    for(auto to:trans[src]){
        if(!visited[to])
        dfs2(to);
    }
}


class Solution{
	public:

    int kosaraju(int V, vector<int> adj[]) {
        
        order.clear();
        for(int i=0;i<=V;i++)trans[i].clear();
        visited.assign(V,false);
        
        for(int i=0;i<V;i++){
            for(auto to:adj[i]){
                trans[to].push_back(i);
            }
        }
        
        for(int i=0;i<V;i++)
        if(!visited[i])dfs1(adj,i);
        
        visited.assign(V,false);
        int ans =0;
        
        for(int i=order.size()-1;i>=0;i--){
            if(!visited[order[i]]){
                ans++;
                dfs2(order[i]);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends