/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

====================================================================>>> best question 
after looking soln i solved
using fenwick tree we can solve it
what we can do is we can start traversing from right
for right most element ans will be zero ao start BIT with 0
(Assuming elemnt value as 5 )now we will update upto x+5 positions with difference 1 where x = any big number to avoid runtime error
this show that upto x+5 postion there is a number
now if we get number less than 5 than we will update only upto x+2 (assuming element value 2)
and we can easily check that there is a number greater than 2 already at those position by getrangesum query of fenwick tree
similarly we can do with all elements and so on......
*/


vector<int>bit;
int n;

void update(int idx,int value){
    for(;idx<=20000;idx = idx|(idx+1))bit[idx]+=1;
}

int getmin(int idx){
    idx--;
    int cnt =0;
    for(;idx>=0;idx = (idx&(idx+1))-1)cnt+=bit[idx];
    return cnt;
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        bit.assign(n+200010,0);
        vector<int>ans(n,0);
        
        for(int i=n-1;i>=0;i--){
            ans[i]=getmin(nums[i]+10000);
            update(nums[i]+10000,1);
        }
        
        return ans;
    }
};