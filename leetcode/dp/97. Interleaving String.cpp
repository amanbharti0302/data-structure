/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/

class Solution {
public:
    int dp[102][102];
    string a,b,c;
        
    bool cal(int n,int m,int k){
        if(n==0&&m==0&&k==0)return true;
        //if(n==0||m==0||k==0)return false;
        if(dp[n][m]!=-1)return dp[n][m];
        
        bool ans = false;
        if(n>0&&a[n-1]==c[k-1])ans = ans||cal(n-1,m,k-1);
        if(m>0&&b[m-1]==c[k-1])ans = ans||cal(n,m-1,k-1);
        return dp[n][m] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=s1.length()+s2.length())return false;
        a=s1,b=s2,c=s3;
        memset(dp,-1,sizeof(dp));
        return cal(s1.length(),s2.length(),s3.length());
    }
};