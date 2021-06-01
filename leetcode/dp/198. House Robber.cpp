/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
======================================================================>>>>0-1 kanpsack problem
we have two option either take adjacent or take current ,
if we take current elemnt than go to element nest to next else go to next
*/

///////////////////////////////////////////////////////recursive
int dp[500];
int cal(vector<int>&a,int n){
    if(n<=0)return 0;
    if(dp[n]!=-1)return dp[n];
    return dp[n] = max(cal(a,n-1),a[n-1]+cal(a,n-2));
}

class Solution {
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return cal(nums,nums.size());
    }
};


///////////////////////////////////////////////////////iterative
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[500];
        if(nums.size()==0)return 0;
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=1;i<nums.size();i++)dp[i+1]=max(nums[i]+dp[i-1],dp[i]);        
        return dp[nums.size()];
    }
};