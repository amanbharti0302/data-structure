/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

=========================================================================> Approach
Simple implementation by taking vector string of size equal to number of rows and i keep record whether i am going down or
going up using a boolean and keep push backing characters according to that
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;

        vector<string>ans(numRows);
        int i=0,ch=0,cnt=0,n=s.length();        
        while(i<n){
            ans[cnt].push_back(s[i]);
            if(ch==0)cnt++;
            else cnt--;
            
            if(cnt==0&&ch==1)ch=0;
            else if(cnt==numRows-1&&ch==0)ch=1;
            i++;
        }
        
        string res="";
        for(int i=0;i<numRows;i++){res+=ans[i];}
        return res;
    }
};