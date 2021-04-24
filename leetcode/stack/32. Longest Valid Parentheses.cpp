/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 
*/

class Solution {
public:
    int cal(string s,int type){
        int ans =0;
        int o=0,c=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')o++;
            else c++;
            if(o==c){ans = max(ans,o+c);}
            if(c>o&&type==1){o=0,c=0;}
            if(o>c&&type==2){o=0,c=0;}
        }
        
        return ans;
    }
    
    int longestValidParentheses(string s) {
        int ans = 0;
        ans = max(ans,cal(s,1));
        reverse(s.begin(),s.end());
        ans = max(ans,cal(s,2));
        return ans;
    }
};