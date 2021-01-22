/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
Follow up: Could you write an algorithm with O(log n) runtime complexity?
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

==============================================>>>Using binary search we can easily solve it
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>sol(2,-1);
        if(nums.size()==0)return(sol);
        sol[0]=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        sol[1]=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        
        
        if(sol[0]<0||sol[0]>=nums.size()||nums[sol[0]]!=target)sol[0]=-1;
        if(sol[1]>=nums.size()||sol[1]<0||nums[sol[1]]!=target)sol[1]=-1;
        return sol;
    }
};