#include<bits/stdc++.h>
using namespace std;

int n;
int seg[500005];
int a[100005];

void build(int v,int tl,int tr){
    if(tl==tr){seg[v]=a[tl]; return;}            //leaf node found
    int mid = (tl+tr)/2;
    build(2*v,tl,mid);                           //left subtree v= 2*v
    build(2*v+1,mid+1,tr);                       //right subtree v = 2*v+1
    seg[v] = seg[2*v]+seg[2*v+1];                //assign sum of left and right subtree to parent node
}

void update(int v,int tl,int tr,int ind,int val){
    if(tl==tr){seg[v]=val; return;}               //required position found like binary search tree
    int mid = (tl+tr)/2;        
    if(ind<=mid)update(2*v,tl,mid,ind,val);        
    else update(2*v+1,mid+1,tr,ind,val);
    seg[v] = seg[2*v]+seg[2*v+1];                  //update in parent node
}

int sum(int v,int tl,int tr,int l,int r){          //[l,r] = region whose sum we want to return
    if(l>r) return 0;
    if(l==tl&&r==tr) return seg[v];                //when whole range found in a node return sum of entire region
    int mid = (tl+tr)/2;                           //if whole region is greater then required range we have to go segment of that region
    return sum(2*v,tl,mid,l,min(r,mid))+sum(2*v+1,mid+1,tr,max(l,mid+1),r);
}

int32_t main(){
    cin>>n;                                         //size of array
    for(int i=0;i<n;i++) cin>>a[i];
    build(1,0,n-1);
    
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){                                //type =1 for update query
            int x,pos;
            cin>>pos>>x;                            //pos = position (1 based indexing) , val = value for update
            a[pos] = x;
            pos--;
            update(1,0,n-1,pos,x);
        }
        else{                                       //type != 1 for sum query
            int llim,rlim;
            cin>>llim>>rlim;
            llim--;rlim--;
            cout<<sum(1,0,n-1,llim,rlim)<<endl;     //llim = left limit , rlim = right limit  (1 based indexing )
        }
   }
    return 0;
}