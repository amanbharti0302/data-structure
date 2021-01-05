/*
====================Finding Bridges in O(N+M)===================
*/
#include<bits/stdc++.h>
using namespace std;

vector<bool>visited(100005,false);
vector<int>adj[100005];
int in[100005];
int low[100005];
int timer;

void dfs(int v,int p=-1){
    visited[v]=true;
    in[v]=low[v]=timer++;
    for(auto to:adj[v]){
        if(to==p)continue;
        else if(visited[to]==true){
            low[v] = min(low[v],in[to]);
        }
        else{
            dfs(to,v);
            low[v] = min(low[v],low[to]);
            if(low[to]>low[v])cout<<"Bridge found : Parent = "<<v<<" Child = "<<to<<endl;
        }
    }
}

int32_t main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1);
    return 0;
}