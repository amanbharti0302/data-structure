/*
Given an m x n board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/


bool dfs(int i,int j,int k,string word,vector<vector<char>>& board){
    if(board[i][j]==word[k])board[i][j]='.';
    else return false;
    
    if(k==word.length()-1)return true;
    
    int m = board.size(),n = board[0].size();
    int ar[4]={-1,1,0,0};
    int br[4]={0,0,-1,1};
    
    bool ans = false;
    
    for(int l=0;l<4;l++){
        int x = ar[l]+i,y = br[l]+j;
        if(x>=0&&y>=0&&x<m&&y<n&&board[x][y]==word[k+1])ans = ans|dfs(x,y,k+1,word,board);
        if(ans==true)break;
    }
    
    board[i][j]=word[k];
    return ans;
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        
        bool ans = false;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){ans = ans|dfs(i,j,0,word,board);}
                if(ans==true)return true;
            }
        }
        
        return ans;
    }
};