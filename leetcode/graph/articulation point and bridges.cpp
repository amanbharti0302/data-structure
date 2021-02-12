#include<bits/stdc++.h>
using namespace std;
int n,m,timer=1;
vector<int>adj[100],visited(100,false);
int in[100],low[100];
vector<pair<int,int>>bridges;
vector<int>articulation;

void dfs1(int src,int p=-1){
	visited[src]=true;
	in[src]=low[src]=timer++;
	for(auto to :adj[src]){
		if(to==p)continue;
		if(visited[to]){
			low[src] = min(low[src],in[to]);
		}
		else{
			dfs1(to,src);
			low[src]=min(low[src],low[to]);
			if(low[to]>in[src])bridges.push_back({min(src,to),max(src,to)});
		}
	}
}

void dfs2(int src,int p=-1){
	visited[src]=true;
	in[src]=low[src]=timer++;
	int children =0;

	//cout<<src<<" ";

	for(auto to:adj[src]){
		if(to==p)continue;
		else if(visited[to]){
			low[src] = min(low[src],in[to]);
		}
		else{
			dfs2(to,src);
			low[src]=min(low[src],low[to]);
			if(low[to]>=in[src]&&p!=-1){
				articulation.push_back(src);
			}
			++children;
		}
	}
	if(p==-1&&children>=2)articulation.push_back(src);
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i=0;i<n;i++){if(!visited[i])dfs1(i);}
	for(int i=0;i<100;i++){visited[i]=false;in[i]=low[i]=0;}
	timer=1;
	for(int i=0;i<n;i++){if(!visited[i])dfs2(i,-1);}

	sort(bridges.begin(),bridges.end());
	sort(articulation.begin(),articulation.end());
	cout<<articulation.size()<<endl;
	for(int i=0;i<articulation.size();i++){
		cout<<articulation[i]<<" ";
	}
	cout<<endl;

	cout<<bridges.size()<<endl;
	for(int i=0;i<bridges.size();i++){
		cout<<bridges[i].first<<" "<<bridges[i].second<<endl;
	}

	return 0;
}