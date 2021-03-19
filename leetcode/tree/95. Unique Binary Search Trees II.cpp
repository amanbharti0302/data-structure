/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*>helper(int s,int e){
        
        vector<TreeNode*>ans;
        
        if(s>e){ans.push_back(NULL);return ans;}
        
        for(int i=s;i<=e;i++){
            vector<TreeNode*>left=helper(s,i-1);
            vector<TreeNode*>right=helper(i+1,e);
            for(auto l:left){
                for(auto r:right){
                    TreeNode *root = new TreeNode(i);
                    root->left =l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};