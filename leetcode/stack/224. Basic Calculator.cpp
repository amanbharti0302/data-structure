/*
Given a string s representing an expression, implement a basic calculator to evaluate it.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
*/

class Solution {
public:
    int oper(int a,int b,char op){
        if(op=='+')return a+b;
        return a-b;
    }
    
    int calculate(string s) {
        int ans = 0;
        stack<char>s1;
        stack<int>st;
        st.push(0);
        
        int i= 0;
        
        while(i<s.length()){
            if(s[i]>='0'&&s[i]<='9'){
                int temp = 0;
                while(i<s.length()&&s[i]>='0'&&s[i]<='9'){
                    temp = temp*10+(s[i]-'0');
                    i++;
                }
                
                if(s1.empty()||s1.top()=='(')st.push(temp);
                else {
                    char op = s1.top();
                    s1.pop();
                    int last = st.top();st.pop();
                    st.push(oper(last,temp,op));
                }
            }
            else if(s[i]=='('){
                s1.push('(');
                st.push(0);
                if(s[i+1]!='+'&&s[i+1]!='-')s1.push('+');
                
                i++;
            }
            else if(s[i]==')'){
                s1.pop();
                int temp = st.top();st.pop();
                if(s1.empty())st.push(temp);
                else {
                    char op = s1.top();
                    s1.pop();
                    int last = st.top();st.pop();
                    st.push(oper(last,temp,op));
                }
                
                i++;
            }
            
            else if(s[i]=='+'||s[i]=='-'){
                s1.push(s[i]);
                i++;
            }
            else i++;
        }
        
        return st.top();
    }
};