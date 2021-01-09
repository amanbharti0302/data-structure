/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Example 1:
Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6

======================================>>>>My approach
It is a standard problem as for column 1 and row 1 we have only one way to go anywhere
But accept column and row 1 we have 2 options we can reach at a particular cell from above cell or left cell
so using dp from column2 and row 2 total number of ways to a particular cell is sum of number of ways to above and left cell
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        for(int i=1;i<=n;i++)dp[1][i]=1;
        for(int i=1;i<=m;i++)dp[i][1]=1;
        
        for(int i=2;i<=m;i++)
        for(int j=2;j<=n;j++)
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
        
        return dp[m][n];
    }
};