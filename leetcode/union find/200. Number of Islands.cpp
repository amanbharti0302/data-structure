/*
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water. 
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

===========================>My approach
I used simple grid based dfs
*/
int n,m;
int cnt ;
void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& visited){
    if(i<0||j<0||i>=n||j>=m)return;
    if(grid[i][j]=='0')return;
    if(visited[i][j])return;
    visited[i][j]=true;
    int a1[] = {-1, 1, 0, 0};
    int a2[] = {0, 0, -1, 1};
    for(int k=0;k<4;k++)dfs(i+a1[k],j+a2[k],grid,visited);
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if(n==0)return 0;
        m = grid[0].size();
        cnt=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(grid[i][j]=='0'||visited[i][j])continue;
            cnt++;
            dfs(i,j,grid,visited);
        }
        
        return cnt;
    }
};