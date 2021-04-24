/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0

================================================>>>>Approach
for every cell i,j if(a[i][j]==0)then continue
if(a[i][j]==1){
    then if(a[i-1][j-1]==0)then we can't extend square from previous row and colmn
    else we can extend from previous by 1 so previous will be minimum of calculated values at (i-1,j-1),(i-1,j),(i,j-1)
}

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        int ans = 0,n=a.size(),m=a[0].size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){dp[i][1]=(a[i-1][0]=='1')?1:0;ans = max(ans,dp[i][1]);}
        for(int i=1;i<=m;i++){dp[1][i]=(a[0][i-1]=='1')?1:0;ans = max(ans,dp[1][i]);}
        
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                if(a[i-1][j-1]=='0')continue;
                if(a[i-2][j-2]=='0'){dp[i][j]=1;ans = max(ans,dp[i][j]);continue;}
                dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans*ans;
    }
};

