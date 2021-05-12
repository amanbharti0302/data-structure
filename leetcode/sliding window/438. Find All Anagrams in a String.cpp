/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

class Solution {
public:
    bool valid(int cnt[],int cnt2[]){
        for(int i = 0;i<26;i++)if(cnt[i]!=cnt2[i])return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int cnt [26]={0},k  =p.length();
        int cnt2[26]={0};
        for(int i = 0;i<p.length();i++)cnt2[p[i]-'a']++;
        
        for(int i = 0;i<s.length();i++){
            if(i>=k)cnt[s[i-k]-'a']--;
            cnt[s[i]-'a']++;            
            if(i<k-1)continue;
            if(valid(cnt,cnt2))ans.push_back(i-k+1);
        }
            
        return ans ;
    }
};