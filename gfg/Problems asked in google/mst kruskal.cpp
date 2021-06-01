/*https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//kruskal
vector<int>ran,parent,visited;
int n;
vector<vector<int>>edges;

void make_set(int v){
    parent[v]=v;
    ran[v]=0;
}

int find_set(int v){
    if(v==parent[v])return v;
    return parent[v]=find_set(parent[v]);
}

void union_set(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(ran[a]<ran[b])swap(a,b);
        parent[b]=a;
        if(ran[a]==ran[b])ran[a]++;
    }
}



class Solution{
	public:
    int spanningTree(int V, vector<vector<int>> a[]) {
        edges.clear();
        visited.assign(V,false);
        ran.assign(V,0);
        parent.assign(V,0);
        
        for(int i=0;i<V;i++)make_set(i);
        int cost =0;
        
        for(int i=0;i<V;i++)
        for(int j=0;j<a[i].size();j++)
        edges.push_back({a[i][j][1],i,a[i][j][0]});
        
        sort(edges.begin(),edges.end());
        
        for(int i=0;i<edges.size();i++){
            if(find_set(edges[i][1])!=find_set(edges[i][2])){
                cost+=edges[i][0];
                union_set(edges[i][1],edges[i][2]);
            }
        }
        
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends