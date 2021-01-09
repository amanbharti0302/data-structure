/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and space is marked as 1 and 0 respectively in the grid.
Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
=======================================================>>>My approach
for a row we have two options if we encounter 1 at grid aur earler than we have no way to go ahead from there
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int dp[n+1][m+1];
        
        if(obstacleGrid[0][0]==1)dp[0][0]=-1;
        else dp[0][0]=1;
        
        for(int i=1;i<n;i++)
        if(i==0)dp[i][0]=1;
        else if(dp[i-1][0]==-1||obstacleGrid[i][0]==1)dp[i][0]=-1;
        else dp[i][0]=1;
        
        for(int i=1;i<m;i++)
        if(i==0)dp[0][i]=1;
        else if(dp[0][i-1]==-1||obstacleGrid[0][i]==1)dp[0][i]=-1;
        else dp[0][i]=1;
        
        for(int i=1;i<n;i++)
        for(int j=1;j<m;j++){
            if(obstacleGrid[i][j]==1)dp[i][j]=-1;
            else if(dp[i-1][j]==-1&&dp[i][j-1]==-1)dp[i][j]=-1;
            else if(dp[i-1][j]==-1)dp[i][j] = dp[i][j-1];
            else if(dp[i][j-1]==-1)dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
        
        return max(0,dp[n-1][m-1]);
    }
};