/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2

===========================================>>>>My Approach
We can reach at any position from the position which is divisible by the current position

*/

class Solution {
public:
    int dp[10005][105];
    int sqr[10005];
    
    int cal(int sum,int idx){
        if(sum==0)return 0;
        if(idx<=0||sum<0)return 10008;
        
        if(dp[sum][idx]!=-1)return dp[sum][idx];
        
        if(sqr[idx]>sum)return dp[sum][idx] = cal(sum,idx-1);
        return dp[sum][idx] = min(1+cal(sum-sqr[idx],idx),cal(sum,idx-1));
    }
    
    int numSquares(int n) {
        for(int i=1;i<=10000;i++)sqr[i]=i*i;
        memset(dp,-1,sizeof(dp));
        return cal(n,sqrt(n)+1);
    }
};