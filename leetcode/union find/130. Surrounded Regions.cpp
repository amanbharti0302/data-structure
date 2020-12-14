/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

===========================================>My Approach
What i did is that i simply do grid based dfs using recursion when i get any border in region than i set boolean ch = false;
else it is set to true and that region is stored in temp after which it is filled with 'X'
*/
bool ch;
int n,m;
vector<pair<int,int>>temp;

void checkdfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>>& visited){
    if(i<0||i>=n||j<0||j>=m)return;    // To Stop Grid based dfs if we go i or j out of index bound,thus saved runtime error
    
    if(board[i][j]=='X'){return;}      //as we have to traverse only on grid which is 'O' so we have to go back if we encountered 'X'
    
    if(visited[i][j])return;            //if node is already visited than go back
    
    visited[i][j] = true;               // if not visited than set it to visited
    temp.push_back({i,j});              // push to temp so that if boolean reamins true than we can replace this section

    if(i==0||i==n-1||j==0||j==m-1)ch=false;     //if we region touches boundary than set boolean false so that we will not replace temp stored
    int a1[] = {-1 ,1, 0, 0};               //best way to go all adjacent blocks in grid dfs 
    int a2[] = {0 ,0 ,-1 ,1};
    for(int k=0;k<4;k++)checkdfs(i+a1[k],j+a2[k],board,visited);
}

void filldfs(vector<vector<char>>& board){
    for(auto x:temp){board[x.first][x.second]='X';}   //to fill all temp stored position with 'X'
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n==0)return;
        m = board[0].size();
        vector<vector<bool>>visited(n+5,vector<bool>(m+5,false));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {   
            if(board[i][j]=='X')continue;
            temp.clear();
            if(visited[i][j])continue;
            ch=true;                                 //when start new region than set boolean true
            checkdfs(i,j,board,visited);             //it check that region touches boundary or not also stores index of region in temp
            if(ch==true){filldfs(board);}            //if boolean reamins true than we will replace that region
        }
    }
};