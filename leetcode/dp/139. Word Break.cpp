/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/

class Solution {
public:
    
    map<string,bool>dp;
    string code(int ind,int x){
        return to_string(ind)+to_string(x);
    }
    
    bool cal(string &s,int ind,vector<string>& d){
        if(ind==s.length())return true;
        bool ans = false;
        
        for(int i=0;i<d.size();i++){
            if(d[i].length()>s.length()-ind)continue;
            string temp = code(ind,i);
            if(dp.find(temp)!=dp.end()){ans = ans|dp[temp];continue;}
            if(s.substr(ind,d[i].length())==d[i]){
                bool ch = dp[temp] = cal(s,ind+d[i].length(),d);
                ans = ans|ch;
            }
            else dp[temp]=false;
        }
        return ans;
    }
    
    bool wordBreak(string s, vector<string>& d) {
        return cal(s,0,d);
    }
};