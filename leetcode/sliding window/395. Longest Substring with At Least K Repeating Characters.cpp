/*
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/

class Solution {
public:
    int valid(int cnt[],int k){
        for(int i= 0;i<26;i++){if(cnt[i]<k&&cnt[i]>0)return i;}
        return -1;
    }
    
    int longestSubstring(string s, int k) {
        int ans = 0,lmax=0;
        int cnt[26]={0};
        for(int i= 0;i<s.length();i++)cnt[s[i]-'a']++;
        int pos = valid(cnt,k);
        if(pos==-1)return s.length();
        
        for(int i = 0;i<s.length();i++)if(s[i]==pos+'a'){pos = i;break;}
        
        
        return max(longestSubstring(s.substr(0,pos),k),longestSubstring(s.substr(pos+1,s.length()-pos-1), k));
    }
};