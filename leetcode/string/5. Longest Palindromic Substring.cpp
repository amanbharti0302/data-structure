/*
Given a string s, return the longest palindromic substring in s.
Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

========================================================>>>>>>>
Standard Dp Problem in which we have to take dp table of size string size where row is starting point and column is length of possible string
and we check that whether from a specific character is it possible to draw a palindrome of a fix length
*/


class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.length()+1;
        bool dp[n+1][n+1];
        memset(dp,false,sizeof(dp));
        
        int strt =1,maxlength = 1;
        for(int i=1;i<=n;i++)dp[i][i]=true;
        
        for(int i=1;i<n;i++)if(s[i-1]==s[i]){dp[i][i+1]=true;strt=i;maxlength=2;}      
        
        for(int l=3;l<=n;l++){
            for(int i=1;i<=n-l;i++){
                int j=i+l-1;
                if(dp[i+1][j-1]==true&&s[i-1]==s[j-1])
                {   dp[i][j]=true;
                    if(l>maxlength){strt=i;maxlength=l;}
                }
            }
        }
        
        string ans ="";
        for(int i=0;i<maxlength;i++){ans+=s[strt-1];strt++;}
        return ans;
        
    }
};