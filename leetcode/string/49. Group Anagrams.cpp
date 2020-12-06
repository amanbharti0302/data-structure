/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


====================================================>>>My approach
look at example 1 
eat, tea and ate are anagrams means if we sort all of them then they all three will be same 
so why not sort every string and after that we will sort vector of array
but we may lost original string 
so to keep original array we will use vector pair before sorting
now we can easily make groups

======================================================>> Code
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>sol;
        if(strs.size()==0)return sol;
        vector<pair<string,string>>s(strs.size());
        
        for(int i=0;i<strs.size();i++){
            s[i].first=s[i].second=strs[i];
            sort(s[i].first.begin(),s[i].first.end());
        }
        
        sort(s.begin(),s.end());
        vector<string>temp;
        
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i].second);
            string t = s[i].first;
            while(i+1<s.size()&&s[i+1].first==t){i++;temp.push_back(s[i].second);}
            sol.push_back(temp);
            temp.clear();
        }
        
        return sol;
    }
};