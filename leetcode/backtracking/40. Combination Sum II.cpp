/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

vector<vector<int>>sol;

void dfs(int ind,int sum,vector<int>ans,vector<int>& a, int b){
    if(sum==b){sol.push_back(ans);return;}
    if(sum>b||ind>=a.size()){return;}
    
    map<int,int>mp;
    for(int i=ind;i<a.size();i++){
        if(mp[a[i]]>0)continue;
        mp[a[i]]++;
        if(a[i]+sum<=b){
            ans.push_back(a[i]);
            dfs(i+1,sum+a[i],ans,a,b);
            ans.pop_back();
        }
    }    
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& a, int b) {
        sol.clear();
        sort(a.begin(),a.end());
        dfs(0,0,{},a,b);
        return sol;
    }
};