/*
Given an integer array nums, find the sum of the elements between indices left and right inclusive, where (left <= right).
Implement the NumArray class:
NumArray(int[] nums) initializes the object with the integer array nums.
int sumRange(int left, int right) returns the sum of the elements of the nums array in the range [left, right] inclusive (i.e., sum(nums[left], nums[left + 1], ... , nums[right])).
Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
*/

class NumArray {
public:
    vector<int>pr;
    NumArray(vector<int>& nums) {
        pr.push_back(0);
        int sum = 0;
        for(auto x:nums){sum+=x;pr.push_back(sum);}
    }
    
    int sumRange(int left, int right) {
        return pr[right+1]-pr[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */