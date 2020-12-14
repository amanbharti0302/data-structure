#include<bits/stdc++.h>
using namespace std;
vector<int>ar;                  //ar = array where we store elements
int n;                         //n = Size of array
vector<int> bit;

void add_bit(int idx,int value){
    for(;idx<n;idx=idx|(idx+1))bit[idx]+=value;
}

int sum_bit(int idx){
    if(idx==-1)return 0;
    int ans =0;
    for(;idx>=0;idx = (idx&(idx+1))-1)ans+=bit[idx];
    return ans;
}

void update(int i, int val) {
    add_bit(i,val-ar[i]);
    ar[i]=val;
}

int sumRange(int i, int j) {return sum_bit(j)-sum_bit(i-1);}

int main(){
  //////////////////////////////For Example We are taking n= 7
  ///////////////////////////// and array = 7 8 1 2 3 4 5
  cin>>n;
  ar.assign(n,0);                       //Assigning Size Of Array
  bit.assign(n,0);                      //Assigning Size of Binary Indexed tree as it's Space compexity is O(n)
  
  for(int i=0;i<n;i++){
    cin>>ar[i];                         //Taking value of elements in array
    add_bit(i,ar[i]);                    //Update Binay indexed tree
  }

  /////////////////////////////////////////////// To get sum of a range
  //We want sum from index 2 to 5
  cout<<sumRange(2,5)<<" { Before Updating }"<<endl;  
  //Now We want to update array of element at index 4 to value  = 5
  //Here to update what we can do 
  // we can simply perform add operation and add difference of old value and new value;
  update(4,5);                            //Updating binary indexed tree
  ar[4] = 5;                              //upadting original array
  
  cout<<sumRange(2,5)<<" { After Updating }"<<endl;
  for(int i=0;i<n;i++)cout<<ar[i]<<" ";
}