/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2

======================================================>>>
for every amount we have all coins options so recursively we can check with all coins for each amount and by memoization we can 
save from repition
*/
int dp[10005];
int cal(vector<int>&c,int amt){
    if(amt==0)return 0;
    if(amt<0)return INT_MAX;
    int sz = c.size();
    if(dp[amt]!=-1)return dp[amt];
    
    int ans =INT_MAX;
    for(int i=0;i<sz;i++)
    ans = min(ans,cal(c,amt-c[i]));
    
    return dp[amt] = (ans==INT_MAX)?ans:ans+1;
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = cal(coins,amount);
        return ans==INT_MAX?-1:ans;
    }
};