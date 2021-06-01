/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input. 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
Example 4:

Input: candidates = [1], target = 1
Output: [[1]]
Example 5:

Input: candidates = [1], target = 2
Output: [[1,1]]

*/

vector<vector<int>>sol;

void dfs(int b,int ind,vector<int>ans,int sum,vector<int> &a){
    if(sum==b){sort(ans.begin(),ans.end());sol.push_back(ans);return;}
    if(sum>b)return;
    
    for(int i=ind;i<a.size();i++){
        if(sum+a[i]<=b){
            ans.push_back(a[i]);
            dfs(b,i,ans,sum+a[i],a);
            ans.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int b) {
        sol.clear();
        sort(a.begin(), a.end());
        vector<int>a2;
        
        map<int,int>mp;
        for(int i=0;i<a.size();i++)
        if(mp[a[i]]>=1)continue;
        else {a2.push_back(a[i]);mp[a[i]]++;}
        
        dfs(b,0,{},0,a2);
        sort(sol.begin(),sol.end());
        return sol;
    }
};