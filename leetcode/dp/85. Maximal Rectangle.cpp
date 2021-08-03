/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = (int)matrix.size();
        if(n==0)return 0;
        int m  = matrix[0].size();
        
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(j==0)dp[i][j] = matrix[i][j]-'0';
                else if(matrix[i][j]=='1')dp[i][j] = dp[i][j-1]+1;
            }
        }
        
        
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(dp[i][j] == 0)continue;
                else {                    
                    int k = i;
                    int mnm = dp[i][j];
                    
                    while(k<n&&dp[k][j]>=1){
                        mnm = min(mnm,dp[k][j]);
                        ans = max(ans,(k-i+1)*mnm);
                        k++;
                    }
                    
                }
            }
        }
        
        return ans;
    }
};