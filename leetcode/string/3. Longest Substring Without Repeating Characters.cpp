/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without repeating characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

=======================================================================>>>> MY Approach

In this Question i used two pointer approach with hashing or we can say that sliding window algorithm with hashing
what i did is that i started traversing through string with on pointer and storing it in hash until i encountered that a 
character at a prticular position is already hashed and i kept another pointer at starting point.

When i encounter any character already hashed that means now we have to ignore all the characters upto that position so we erase all character 
upto that position using second pointer.

length of all these window is stored in a temp variable
now regulaly compare the window size with maximum size of ans till now.
thus we have to store maxm window size.

======================================================================>>>>>>> CODE
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int ans =0,temp=0,n=s.length();
        int l=0;   //l = strating pointer
        
        for(int i=0;i<n;i++){      //i = pointer which is ahead of l               
            if(m.find(s[i])!=m.end()){
                ans=max(ans,temp);
                temp=i-m[s[i]];
                for(;l<=m[s[i]];l++)m.erase(s[l]);
                m[s[i]]=i;
                continue;
            }
            m[s[i]]=i;
            temp++;
            ans=max(ans,temp);
        }
        return ans;
    }
};