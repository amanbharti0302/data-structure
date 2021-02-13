// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

vector<int>in,low,visited;
int timer =1;
vector<bool>onstack;
stack<int>s;
vector<vector<int>>res;


void dfs(int src,vector<int> adj[]){
    in[src] = low[src] = timer++;
    onstack[src]=true;
    visited[src]=true;
    s.push(src);
    
    for(auto to:adj[src]){
        if(visited[to]&&onstack[to])
        low[src] = min(low[src],in[to]);
        else if(!visited[to]){
            dfs(to,adj);
            if(onstack[to])
            low[src]=min(low[src],low[to]);
        }
    }
    
    if(in[src]==low[src]){
        vector<int>sol;
        while(!s.empty()){
            onstack[s.top()]=false;
            sol.push_back(s.top());
            if(s.top()==src){s.pop();break;}
            s.pop();
        }
        sort(sol.begin(),sol.end());
        res.push_back(sol);
    }
}

class Solution{
	public:

    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        timer=1;
        res.clear();
        onstack.assign(V+2,0);
        in.assign(V+2,0);
        low.assign(V+2,0);
        visited.assign(V+2,false);
        onstack.assign(V+2,false);
        
        for(int i=0;i<V;i++)
        if(!visited[i])dfs(i,adj);
        sort(res.begin(),res.end());
        return res;
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends