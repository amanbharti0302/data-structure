/*
Given two strings s and t of lengths m and n respectively, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".
Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int req[260]={0};
        int curr[256]={0};
        set<char>st;
        
        for(int i = 0;i<t.length();i++){req[t[i]]++;st.insert(t[i]);}
        int ans = INT32_MAX,ind = -1,cnt = 0,f = 0;
        
        
        for(int i = 0,j= 0;i<s.length();i++){
            if(req[s[i]]>0){curr[s[i]]++;f++;}
            if(req[s[i]]>0&&curr[s[i]]==req[s[i]])cnt++;
            
            while(cnt==st.size()&&f>=t.length()){
                if(ans>i-j+1){
                    ind = j;
                    ans = i-j+1;
                }
                if(req[s[j]]>0&&curr[s[j]]==req[s[j]])cnt--;
                if(req[s[j]]>0){curr[s[j]]--;f--;}
                j++;
            }
        }
        
        if(ind == -1)return "";
        return s.substr(ind,ans);
    }
};