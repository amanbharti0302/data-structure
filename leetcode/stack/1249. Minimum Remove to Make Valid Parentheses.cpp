/*
Given a string s of '(' , ')' and lowercase English characters. 
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
Example 4:

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"

*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int  c =0,curo = 0;
        
        int cnto[s.length()],cntc[s.length()];
        
        for(int  i = 0;i<s.length();i++)
        if(s[i]==')')c++;
        
        for(int i= 0;i<s.length();i++){
            if(s[i]!='('&&s[i]!=')'){ans+=s[i];continue;}
            if(s[i]=='('){
                curo++;
                if(curo<=c){ans+=s[i];}
            }
            else{
                if(curo>0){ans+=s[i];curo--;}
                c--;
            }
        }
        
        return ans;
    }
};