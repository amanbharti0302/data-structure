/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
*/
vector<vector<string>>sol;
vector<vector<int>>res;

bool issafe(int c,int r,int n,vector<int>ans){
    for(auto x :ans)if(x==r)return false;
    
    int t = r-1;
    for(int i= ans.size()-1;i>=0;i--){
        if(t==-1)break;
        if(ans[i]==t)return false;
        t--;
    }
    
    t=r+1;
    for(int i=ans.size()-1;i>=0;i--){
        if(t==n)break;
        if(ans[i]==t)return false;
        t++;
    }
    
    return true;
}

void dfs(int c,int n,vector<int>ans){
    if(c==n){
        res.push_back(ans);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(issafe(c,i,n,ans)){
            ans.push_back(i);
            dfs(c+1,n,ans);
            ans.pop_back();
        }
    }
}
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        sol.clear();
        res.clear();
        dfs(0,n,{});
        
        for(int i=0;i<res.size();i++){
            vector<string>temp(n,string(n,'.'));
            for(int j=0;j<n;j++)
            temp[res[i][j]][j]='Q';
            sol.push_back(temp);
        }
        
        return sol;
    }
};