/*
You are given a string s that consists of lower case English letters and brackets. 

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
Example 4:

Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"

*/

class Solution {
public:
    string reverseParentheses(string s) {
        int i = 0;
        string ans = "";
        stack<string>st;
        
        while(s[i]>='a'&&s[i]<='z'&&i<s.length()){
            ans+=s[i];
            if(i>=s.length()||s[i]=='('||s[i]==')')break;
            i++;
        }
        
        st.push(ans);
        
        for(;i<s.length();i++){
            if(s[i]=='('){
                i++;
                string word="";
                while(s[i]>='a'&&s[i]<='z'&&i<s.length()){word+=s[i];i++;}
                st.push(word);
                i--;
            }
            else{
                i++;
                string word="";
                while(s[i]>='a'&&s[i]<='z'&&i<s.length()){word+=s[i];i++;}
                string temp = st.top();
                st.pop();
                reverse(temp.begin(),temp.end());
                string f = st.top();
                st.pop();
                st.push(f+temp+word);
                i--;
            }
        }
        
        return st.top();
    }
};