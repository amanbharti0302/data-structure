/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police. 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [0]
Output: 0

*/

class Solution {
public:
    int dp[105][2];
    
    int cal(int idx,vector<int>& nums,int t){
        if(idx<0)return 0;
        if(t==1&&idx==0){return dp[idx][1]=0;}
        if(dp[idx][t]!=-1)return dp[idx][t];
        return dp[idx][t] = max(cal(idx-1,nums,t),cal(idx-2,nums,t)+nums[idx]);
    }
    
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        if(nums.size()==1)return nums[0];
        return max(cal(nums.size()-2,nums,0),cal(nums.size()-1,nums,1));
    }
};