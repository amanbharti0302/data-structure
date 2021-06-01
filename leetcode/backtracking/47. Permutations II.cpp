/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

vector<vector<int>>sol;
void dfs(int ind,vector<int>ans,vector<int>& nums){
    if(ind==nums.size()){sol.push_back(ans);return;}
    map<int,int>mp;
    
    for(int i=ind;i<nums.size();i++){
        if(mp.find(nums[i])!=mp.end()){continue;}
        mp[nums[i]]++;
        ans.push_back(nums[i]);
        swap(nums[i],nums[ind]);
        dfs(ind+1,ans,nums);
        swap(nums[i],nums[ind]);
        ans.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sol.clear();
        dfs(0,{},nums);
        return sol;
    }
};