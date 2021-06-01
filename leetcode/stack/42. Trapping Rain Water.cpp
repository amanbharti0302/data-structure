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
        int ans = 0,n= h.size();
        
        int pr[n+2],suf[n+2];
        pr[0] = pr[n+1] = suf[0] = suf[n+1] = 0;
        
        for(int i = 0;i<n;i++)pr[i+1] = max(pr[i],h[i]);
        for(int i=n-1;i>=0;i--)suf[i+1] = max(suf[i+2],h[i]);
        
        for(int i = 1;i<=h.size();i++){
            ans+=  max(0,min(suf[i+1],pr[i-1])-h[i-1]);
        }
        
        return ans;
    }
};