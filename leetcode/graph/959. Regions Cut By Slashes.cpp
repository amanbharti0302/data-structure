/*
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.
(Note that backslash characters are escaped, so a \ is represented as "\\".)
Return the number of regions.
Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:
*/



class Solution {
public:
    int n;
    bool visited[32][32][4];
    
    bool valid(int i,int j,int t){
        if(i<0||j<0||i>=n||j>=n)return false;
        if(t>=4||t<0)return false;
        if(visited[i][j][t])return false;
        return true;
    }
    
    void dfs(int i,int j,int t,vector<string>& grid ){        
        if(!valid(i,j,t))return;
        visited[i][j][t] = true;
                
        switch(t){
            case 0:{
                dfs(i-1,j,2,grid);
                break;
            }
            case 1:{
                dfs(i,j+1,3,grid);
                break;
            }
            case 2:{
                dfs(i+1,j,0,grid);
                break;
            }
            case 3:{
                dfs(i,j-1,1,grid);
                break;
            }
            default: break;
        }
        
        if(grid[i][j]=='\\'){
           if(t==2||t==3)dfs(i,j,5-t,grid); 
           else if(t==0||t==1)dfs(i,j,1-t,grid);
        }
        
        else if(grid[i][j]=='/'){
           if(t==0||t==3)dfs(i,j,3-t,grid); 
           else if(t==2||t==1)dfs(i,j,3-t,grid);
        }
        
        else if(grid[i][j]=' ') {
            for(int k = 0;k<4;k++){
                if(k==t)continue;
                dfs(i,j,k,grid);
            }
       }

    }
    
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        int cnt_reg = 0;
        
        memset(visited,false,sizeof(visited));
        
        
        for(int i = 0;i<n;i++)
            for(int j= 0;j<n;j++){
                for(int t = 0;t<4;t++){
                    if(visited[i][j][t])continue;
                    dfs(i,j,t,grid);
                    cnt_reg++;
                }
            }
        
        return cnt_reg;
    }
};