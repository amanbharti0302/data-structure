/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/
/*
============================>>>>Approach 
for every position if both character matches then no problem go one step behind 
if not matches then we have three options 
    i)either insert (n,m-1 as inserted element in n matched with mth element)
    ii)either delete (n-1,m as after deleting nth element in n compare with mth element)
    iii)replacing nth and mth element means now nth and mth characters are same
*/


class Solution {
public:
    int dp[501][501];
    int cal(string &x, string &y,int n,int m){
        if(n==0)return m;
        if(m==0)return n;
        
        if(dp[n][m]!=-1)return dp[n][m];
        
        if(x[n-1]==y[m-1])return dp[n][m] = cal(x,y,n-1,m-1);
        return dp[n][m] = 1+min({cal(x,y,n,m-1),cal(x,y,n-1,m-1),cal(x,y,n-1,m)});
    }
    
    int minDistance(string x, string y) {
        memset(dp,-1,sizeof(dp));
        return cal(x,y,x.length(),y.length());
    }
};