/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mp;
        
        priority_queue<pair<int,int>>pq;
        
        for(int i = 0;i<nums.size();i++)
        mp[nums[i]]++;
        
        for(auto it = mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
        }
        
        while(k--&&!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};