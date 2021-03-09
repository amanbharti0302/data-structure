/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
*/

bool ispossible(int ind,string s,string t){
    if(ind+t.length()>s.length())return false;
    for(int i=ind,j=0;i<ind+t.length();i++)if(s[i]!=t[j++])return false;
    return true;
}

vector<string>sol;
void dfs(int ind,string s,string ans,string ch,vector<string>& dic){
    if(ch==s){sol.push_back(ans);return;}
    if(ans.length()>0)ans+=" ";
    for(int i=0;i<dic.size();i++){
        if(ispossible(ind,s,dic[i])){
            dfs(ind+dic[i].length(),s,ans+dic[i],ch+dic[i],dic);
        }
    }
}

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& dic) {
        sol.clear();
        dfs(0,s,"","",dic);
        return sol;
    }
};