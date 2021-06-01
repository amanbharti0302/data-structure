/*
You are given two strings s and t of the same length. You want to change s to t. Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, the absolute difference between the ASCII values of the characters.
You are also given an integer maxCost.
Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of twith a cost less than or equal to maxCost.
If there is no substring from s that can be changed to its corresponding substring from t, return 0.
Example 1:

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.
Example 2:

Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to charactor in t, so the maximum length is 1.
Example 3:

Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You can't make any change, so the maximum length is 1.
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.length(),ans = 0,sum = 0;
        int diff[len];
        
        for(int i = 0;i<len;i++)diff[i] = abs(s[i]-t[i]);
        
        for(int i = 0,j = 0;i<len;i++){
            sum+=diff[i];
            while(sum>maxCost){
                sum-=diff[j];
                j++;
            }
            if(sum<=maxCost)ans = max(ans,i-j+1);
            
        }
        
        return ans;
    }
};