/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:

Input: heights = [2,4]
Output: 4
*/

class Solution {
public:
    vector<int>nsr(vector<int>& heights){
        int n = heights.size();
        vector<int>ans(n,0);
        stack<int>s;
        
        for(int i = n-1;i>=0;i--){
            if(s.empty()){ans[i]=n;}
            else if(heights[i]>=heights[s.top()]){ans[i] = s.top();}
            else{
                while(!s.empty()&&heights[s.top()]>=heights[i])s.pop();
                if(s.empty())ans[i] = n;
                else ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
    
    vector<int>nsl(vector<int>& heights){
        int n = heights.size();
        vector<int>ans(n,0);
        stack<int>s;
        
        for(int i = 0;i<n;i++){
            if(s.empty()){ans[i]=-1;}
            else if(heights[i]>heights[s.top()]){ans[i] = s.top();}
            else{
                while(!s.empty()&&heights[s.top()]>=heights[i])s.pop();
                if(s.empty())ans[i] = -1;
                else ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        vector<int>nsR = nsr(heights);
        vector<int>nsL = nsl(heights);
        
        for(int i = 0;i<heights.size();i++){
            ans = max(ans,(nsR[i]-nsL[i]-1)*heights[i]);
        }
        
        
        return ans;
    }
};

//-1 -1 2 2 -1 1