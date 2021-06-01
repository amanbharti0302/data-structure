// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
// Notice that the solution set must not contain duplicate triplets.

//==> My approach 
//we can solve it in o(n^2) using two pointer method 


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>sol;
        sort(nums.begin(),nums.end());
        int n = nums.size();
    
        
        for(int i=0;i<n-2;i++){
            if(i!=0&&nums[i]==nums[i-1])continue;
            int p1=i+1,p2=n-1;
            while(p1<p2){
                if(nums[p1]+nums[p2]+nums[i]==0){
                    vector<int>temp = {nums[i],nums[p1],nums[p2]};
                    sol.push_back(temp);
                    
                    while(p1<p2&&nums[p1]==nums[p1+1])p1++;
                    while(p1<p2&&nums[p2]==nums[p2-1])p2--;

                    p1++; p2--;
                }
                else if(nums[p1]+nums[p2]+nums[i]<0)p1++;
                else p2--;
            }
        }
        
        return sol;
    }
};