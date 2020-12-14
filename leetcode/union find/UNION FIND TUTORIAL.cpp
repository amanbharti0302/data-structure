#include<bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>ra_nk;

int find_set(int v){
    if(parent[v]==-1)return v;
    return parent[v] = find_set(parent[v]);             //This is path Compression Technique to optimise
}

void union_set(int a,int b){
    int set1 = find_set(a);
    int set2 = find_set(b);
    if(set1==set2)return;
    
    if(ra_nk[set1]<ra_nk[set2]){                        //rank and parent update
        parent[set1]=set2;   
        ra_nk[set2]+=ra_nk[set1];
    }
    else{
        parent[set2]=set1;
        ra_nk[set1]+=ra_nk[set2];
    }
}

int main(){
    int n;
    cin>>n;
    parent.assign(n,-1);
    ra_nk.assign(n,0);


    return 0;
}