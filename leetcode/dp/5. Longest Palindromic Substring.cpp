/*
Given a string s, return the longest palindromic substring in s.
Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"

=====================================================>>>>>>>>>> Standarad Question Of DP
It is a standard Question Of DP
we can solve it using dynamic programming 
we take a boolean table of size as of string and mark it false and {i,j} shows staus of substring from i to j.
so for status of {i,j} substring we can go {i+1,j-1} and check s[i]&&s[j] if both are true then substring {i,j} is also palindrome.
all substring of length 1 will be palindrome 
and we have to also check all substring of length 2 manually as {i+1,j-1} will be overflow in case of 2 size subtring

i added "#" in the string so that i can make string of 1 based indexing.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#"+s;
        s=t;
        int n = s.length();
        bool dp[n+1][n+1];
        memset(dp,false,sizeof(dp));
        
        int maxlength = 1,ind=1;    //maxlength = maximum length of string and ind = strating index of that maxlength
        
        for(int i=1;i<=n;i++)dp[i][i]=true;
        for(int i=1;i<n;i++)if(s[i]==s[i+1]){dp[i][i+1]=true;maxlength=2;ind=i;}
        
        for(int k=3;k<=n;k++){                  //k= size of substring which we will now process
            for(int i=1;i<=n-k;i++){
                int j = i+k-1;                  //i = starting index and j= end index of substring of length k
                if(dp[i+1][j-1]==true&&s[i]==s[j]){
                    dp[i][j]=true;      
                    maxlength =k;
                    ind  = i;
                }
            }
        }
        
        string ans ="";
        for(int i=ind;i<ind+maxlength;i++)ans+=s[i];
        return ans;        
    }
};