/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
Example 1:

Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
*/


class Solution {
    int dfs(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;
        
        int ar[4] = {-1,1,0,0};
        int br[4] = {0,0,-1,1};
        
        for(int k = 0;k<4;k++){
            int ix = i+ar[k],jy = j+br[k];
            if(ix<0||jy<0||ix>=(int)matrix.size()||jy>=(int)matrix[i].size())continue;
            if(matrix[i][j]<=matrix[ix][jy])continue;
            ans = max(ans,1+dfs(ix,jy,matrix,dp));
        }
        
        return dp[i][j] = ans;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        int ans  = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<(int)matrix[i].size();j++){
                ans = max(ans,1+dfs(i,j,matrix,dp));
            }
        }
        
        return ans;
    }
};