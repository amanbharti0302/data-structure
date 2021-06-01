/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

vector<vector<int>> sol;

void dfs(int i,vector<int>& nums,vector<int>ans){
    if(i==nums.size()){sol.push_back(ans);return;}
    dfs(i+1,nums,ans);
    ans.push_back(nums[i]);
    dfs(i+1,nums,ans);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sol.clear();
        dfs(0,nums,{});
        return sol;
    }
};