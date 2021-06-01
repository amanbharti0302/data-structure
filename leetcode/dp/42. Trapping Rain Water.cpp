/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

*/

class Solution {
public:
    int trap(vector<int>& h) {
        if(h.size()<=2)return 0;
        vector<int>pr(h.size(),0),su(h.size(),0);
        
        pr[0] = h[0];su[h.size()-1] = h[h.size()-1];
        for(int i=1;i<h.size();i++)pr[i] = max(pr[i-1],h[i]);
        for(int i=h.size()-2;i>=0;i--)su[i] = max(su[i+1],h[i]);
        
        int ans = 0;
        for(int i=1;i<=h.size()-2;i++){
            ans+=max(0,min(pr[i],su[i])-h[i]);
        }
        return ans;
    }
};