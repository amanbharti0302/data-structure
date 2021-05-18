/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

 

Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation:
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4

*/

class Solution {
public:
    pair<int,int> dp[50][50];
    
    pair<int,int> solve(int l,int r,vector<int>& arr){
        if(l>r)return make_pair(0,1);
        if(l==r)return make_pair(0,arr[l]);
        
        if(dp[l][r].first!=-1)return dp[l][r];
        
        int minm = INT32_MAX,maxm  = 0;
        
        for(int i =l;i<r;i++){
            pair<int,int>lvalue = solve(l,i,arr);
            pair<int,int>rvalue = solve(i+1,r,arr);
            if(lvalue.second*rvalue.second+lvalue.first+rvalue.first<minm){
                maxm = max(lvalue.second,rvalue.second);
                minm = (lvalue.second*rvalue.second+lvalue.first+rvalue.first);
            }
        }
        return dp[l][r] = make_pair(minm,maxm);
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        for(int i = 0;i<50;i++)
        for(int j = 0;j<50;j++)
        dp[i][j].first = dp[i][j].second = -1;
        
        return solve(0,arr.size()-1,arr).first;
    }
};