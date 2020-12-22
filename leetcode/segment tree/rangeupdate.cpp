// RAnge update using lazy propagation
#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int seg[500005];
int lazy[500005];

///////////////////////////build function will be same as initially lazy array should be zero because of no pending request
void build(int v,int tl,int tr){
    if(tl==tr){seg[v]=a[tl];return;}
    int mid = (tl+tr)/2;
    build(2*v,tl,mid);
    build(2*v+1,mid+1,tr);
    seg[v] = max(seg[2*v ],seg[2*v+1]);
}

void push(int v){                               //update of segment tree and subtree of lazy tree whenever we reach there
    seg[v*2]+=lazy[v];
    seg[v*2+1]+=lazy[v];
    lazy[v*2]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v] = 0;
}

                                                    //in lazy propagation what we do is we update the tree whnever we reach there for query 
                                                    //other wise we store it in another lazy tree
void update(int v,int tl,int tr,int l,int r,int val){       //update of a range 
    if(l>r){return;}
    if(tl==l&&tr==r){
        seg[v]+=val;
        lazy[v]+=val;
        return;
    }
    push(v);
    int mid = (tl+tr)/2;
    update(2*v,tl,mid,l,min(r,mid),val);
    update(2*v+1,mid+1,tr,max(l,mid+1),r,val);
    seg[v] = max(seg[2*v],seg[2*v+1]);
}

int get_max(int v,int tl,int tr,int l,int r){
    if(l>r)return -INFINITY;
    if(l<=tl&&tr<=r)return seg[v];
    push(v);
    int mid = (tl+tr)/2;
    return max(get_max(2*v,tl,mid,l,min(mid,r)),get_max(2*v+1,mid+1,tr,max(mid+1,l),r));
}

int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    build(1,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int type ;
        cin>>type;
        if(type==1){
            int llim,rlim,val;
            cin>>llim>>rlim>>val;
            llim--;rlim--;
            update(1,0,n-1,llim,rlim,val);
        }
        else{
            int llim,rlim;
            cin>>llim>>rlim;
            llim--;rlim--;
            cout<<get_max(1,0,n-1,llim,rlim)<<endl;
        }
    }
    return 0;
}