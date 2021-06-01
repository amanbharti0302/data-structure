/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 ≤ i ≤ j < n.
Follow up: Could you do this in O(n) runtime?
Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [0]
Output: 0
Example 3:

Input: nums = [2,4]
Output: 6
Example 4:

Input: nums = [8,10,2]
Output: 10
Example 5:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0,mask = 0;
        if(nums.size()<=1)return ans;
        
        set<int>s;
        
        for(int i=31;i>=0;i--){
            int val = (1<<i);
            mask = mask|val;
            
            for(int j = 0;j<nums.size();j++)
                s.insert(mask & nums[j]);
            
            int temp = ans|val;
            
            for(auto x: s){
                if(s.count(x^temp)){ans = temp;break;}
            }
            s.clear();
        }
        
        return ans;
    }
};