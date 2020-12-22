#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>>seg(500005);
int a[10005];

pair<int,int>combine(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first)return make_pair(a.first,a.second+b.second);
    if(a.first>b.first)return a;
    return b;
}

void build(int v,int tl,int tr){    
    if(tl==tr){seg[v]=make_pair(a[tl],1);return;}
    int mid = (tl+tr)/2;
    build(2*v,tl,mid);
    build(2*v+1,mid+1,tr);
    seg[v] = combine(seg[2*v],seg[2*v+1]);
}

void update(int v,int tl,int tr,int pos,int val){
    if(tl==tr){seg[v]=make_pair(val,1);return;}
    int mid = (tl+tr)/2;
    if(pos<=mid)update(2*v,tl,mid,pos,val);
    else update(2*v+1,mid+1,tr,pos,val);
    seg[v] = combine(seg[2*v],seg[2*v+1]);
}

pair<int,int>get_max(int v,int tl,int tr,int l,int r){
    if(l>r)return make_pair(INT64_MIN,0);
    if(l==tl&&r==tr){return seg[v];}
    int mid = (tl+tr)/2;
    return combine(get_max(2*v,tl,mid,l,min(r,mid)),get_max(2*v+1,mid+1,tr,max(l,mid+1),r));
}

int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    build(1,0,n-1);

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){                                //for update query 
            int pos,x;
            cin>>pos>>x;
            a[pos]=x;
            update(1,0,n-1,pos,x);
        }
        else{                                       //for getting maximum in range
            int llim,rlim;
            cin>>llim>>rlim;
            llim--;rlim--;
            pair<int,int> ans = get_max(1,0,n-1,llim,rlim);
            cout<<"Maximum : "<<ans.first<<endl;
            cout<<"Nubmber of times it appeared : "<<ans.second<<endl;
        }
    }
    return 0;
}