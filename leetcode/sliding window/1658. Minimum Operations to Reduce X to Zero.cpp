/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.
Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int,int>mp;
        int ans = INT32_MAX;
        int pr[nums.size()+1],suf[nums.size()+1];
        pr[0] = 0;suf[nums.size()]=0;
        for(int i = 0;i<nums.size();i++)pr[i+1] = pr[i]+nums[i];
        for(int i = nums.size()-1;i>=0;i--)suf[i] = suf[i+1]+nums[i];
        for(int i = 0;i<nums.size()+1;i++)mp[pr[i]]=i;
        
        for(int i = 0;i<nums.size()+1;i++){
            if(suf[i]>x)continue;
            if(mp.find(x-suf[i])==mp.end())continue;
            int pos = mp[x-suf[i]];
            if(pos>i)continue;
            int sz = nums.size();
            ans = min(ans,pos+sz-i);
        }
        if(ans ==INT32_MAX)ans = -1;
        return ans;
    }
};