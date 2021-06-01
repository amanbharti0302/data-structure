/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int ans = 0,sum = 0;
        mp[0]++;
        
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            ans+=mp[sum-k];
            mp[sum]++;
        }
        
        return ans;
    }
};