/*
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false. 

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
*/

class Solution {
public:
    unordered_map<string,bool>mp;
    string ret_key(string s1,string s2){return s1+" "+s2;}
    
    bool cal(string s1,string s2){
        
        if(s1==s2)return mp[ret_key(s1,s2)]=true;
        if(s1.length()<=1)return false;
        
        if(mp.find(ret_key(s1,s2))!=mp.end())return mp[ret_key(s1,s2)];
        
        int n = s1.length();
        
        for(int i=1;i<n;i++){
            if(cal(s1.substr(0,i),s2.substr(n-i,i))&&cal(s1.substr(i,n-i),s2.substr(0,n-i)))return mp[ret_key(s1,s2)] =true;
            if(cal(s1.substr(0,i),s2.substr(0,i))&&cal(s1.substr(i,n-i),s2.substr(i,n-i)))return mp[ret_key(s1,s2)]=true;
        }
        
        return mp[ret_key(s1,s2)]=false;
    }
    
    bool isScramble(string s1, string s2) {
        mp.clear();
        return cal(s1,s2);
    }
};