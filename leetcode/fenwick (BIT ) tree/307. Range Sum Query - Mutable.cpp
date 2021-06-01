/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8


====================================================> My approach

I used fenwick tree so that i can easily update and perform range query easily
*/

vector<int> bit;
vector<int>ar;
int n;

void addbit(int idx,int value){
    for(;idx<n;idx=idx|(idx+1)){
        bit[idx]+=value;
    }
}

int sumbit(int idx){
    if(idx==-1)return 0;
    int ans =0;
    for(;idx>=0;idx = (idx&(idx+1))-1)ans+=bit[idx];
    return ans;
}

class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit.assign(n,0);
        ar.assign(n,0);
        for(int i=0;i<n;i++){ar[i]=nums[i];addbit(i,nums[i]);}
    }
    
    void update(int i, int val) {
        addbit(i,val-ar[i]);
        ar[i]=val;
    }
    
    int sumRange(int i, int j) {
        return sumbit(j)-sumbit(i-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */