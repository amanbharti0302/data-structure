/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is. 

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Example 2:

Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4

*/

class Solution {
public:
    int dp[10005][105];
    
    int cal(int n,int k){
        if(dp[n][k]!=-1)return dp[n][k];
        
        if(k==1)return n;
        if(n==0||n==1)return n;
        
        int ans = INT_MAX;
        
        
        int l = 1,r = n;
        
        while(l<=r){
            int i = (l+r)/2;
            
            int left = cal(i-1,k-1);
            int right = cal(n-i,k);
            
            int temp = max(left,right);
            ans = min(ans,temp+1);
            
            if(left<right)l = i+1;
            else r = i-1;
    
        }
                
        return dp[n][k] = ans;
    }
    
    
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return cal(n,k);
    }
};