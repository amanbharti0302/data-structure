/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
*/

class Solution {
public:
    int reverse(int x) {
        bool sign = (x<0)?true:false;
        x=abs(x);
        long long ans =0;
        while(x>0){
            int t = x%10;
            if(ans*10+t>INT_MAX)return 0;
            ans=(ans*10)+t;
            x=x/10;
        }
        if(sign)ans=-1*ans;
        return ans;
    }
};