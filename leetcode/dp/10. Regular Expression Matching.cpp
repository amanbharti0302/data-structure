/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 
'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input: s = "mississippi", p = "mis*is*p*."
Output: false

*/

class Solution {
public:
    int dp[40][40];
    
    bool cal(string s,string p,int n,int m){
        if(n==0&&m==0)return true;
        if(n==0)if(p[m-1]=='*'&&m>=0)return cal(s,p,n,m-2);
        if(n==0||m==0)return false;
        
        if(dp[n][m]!=-1)return dp[n][m];
        if(s[n-1]==p[m-1]||p[m-1]=='.')return dp[n][m] = cal(s,p,n-1,m-1);
        bool ans = false;
        
        if(p[m-1]=='*'){
            ans = cal(s,p,n,m-2);
            if(s[n-1]==p[m-2]||p[m-2]=='.')ans = ans|cal(s,p,n-1,m);
        }
        return dp[n][m] = ans;
    }
    
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return cal(s,p,s.length(),p.length());
    }
};