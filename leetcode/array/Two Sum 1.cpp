//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].

//===========> my approach
//it can be solved by two way, either using two pointer method or using hashing

//using two pointer  tc : O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>a(nums.size());
        for(int i=0;i<nums.size();i++){a[i]=make_pair(nums[i],i);}
        sort(a.begin(),a.end());
        int p1=0,p2=nums.size()-1;
        vector<int>sol;
        
        while(p1<p2){
            if(a[p1].first+a[p2].first==target){
                sol.push_back(a[p1].second);
                sol.push_back(a[p2].second);
                break;
            }
            else if(a[p1].first+a[p2].first<target)p1++;
            else p2--;
        }
        return sol;
    }
};


//using hashing  tc : O(n)
//we will chack for every element whether target-A[i] is already appearead or not.
//if already appeared than it will form a required pair 
//else we will insert this element to hash so that if in future any target-A[i] comes it will find it.