/*
==========================Finding Articulation points =====================================

*/

#include<bits/stdc++.h>
using namespace std;

vector<int>adj[200005];
int in[200005];
int low[200005];
vector<bool>visited(200005,false);
int timer;

void dfs(int v,int p=1){
    int children=0;
    visited[v]=true;
    in[v] = low[v] = timer++;
    for(auto to:adj[v]){
        if(to==p)continue;
        else if(visited[to]){
            //back edge found
            low[v] = min(low[v],in[to]);
        }
        else{
            dfs(to,v);
            low[v] = min(low[to],low[v]);
            if(low[to]>=in[v]&&p!=-1)
            cout<<"Articulation point :-->"<<v<<endl;
            ++children;
        }
    }
    if(p==-1&&children>=2)cout<<"Articulation point :--> "<<v<<endl;
}


int32_t main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);        
    }
    dfs(1,-1);
    
    cerr<<"Time : "<<(int)clock()*1000<<" ms"<<endl;
    return 0;
}