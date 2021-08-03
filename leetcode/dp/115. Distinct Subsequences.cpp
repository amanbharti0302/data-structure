/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).
It is guaranteed the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag


*/


class Solution {
public:
    int numDistinct(string s, string t) {
        int n = (int)t.length();
        int m = (int)s.length();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        dp[0][0] =1;
        int ans = 0;
        
        for(int i = 1;i<=n;i++){
            int sum = dp[i-1][0];
            
            for(int j = 1;j<=m;j++){    
                if(t[i-1]==s[j-1]){
                    dp[i][j] +=sum;
                    if(i==n)ans+=dp[i][j];
                }
                
                sum+=dp[i-1][j];
                cout<<dp[i][j]<<" ";
                
            }
            cout<<endl;
        }
        
        return ans;
    }
};