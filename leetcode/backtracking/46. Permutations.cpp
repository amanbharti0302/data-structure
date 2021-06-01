/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/

vector<vector<int>>sol;

void dfs(int ind,vector<int>ans,vector<int>& nums){
    if(ind==nums.size()){sol.push_back(ans);return;}
    
    for(int i=ind;i<nums.size();i++){
        swap(nums[ind],nums[i]);
        ans.push_back(nums[ind]);
        dfs(ind+1,ans,nums);
        ans.pop_back();
        swap(nums[ind],nums[i]);
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sol.clear();
        dfs(0,{},nums);        
        return sol;
    }
};