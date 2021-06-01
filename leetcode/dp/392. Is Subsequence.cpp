/*
Given two strings s and t, check if s is a subsequence of t.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/

class Solution {
public:
    vector<vector<int>>dp;
    //int dp[101][10005];
    
    int cal(string t,string s,int n,int m){
        if(n==0||m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(t[n-1]==s[m-1])return dp[n][m] = 1+cal(t,s,n-1,m-1);
        return dp[n][m] = max(cal(t,s,n-1,m),cal(t,s,n,m-1));
    }
    bool isSubsequence(string s, string t) {
        dp.assign(t.length()+2,vector<int>(s.length()+2,-1));
        if(cal(t,s,t.length(),s.length())==s.length())return true;
        return false;
    }
};