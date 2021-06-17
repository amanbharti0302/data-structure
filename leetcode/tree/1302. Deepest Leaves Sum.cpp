/*
Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)return 0;
        int ans = 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        int tempsum  = 0;
        
        while(q.size()>1){
            auto temp = q.front();
            q.pop();
            if(temp==NULL){ans = tempsum;tempsum = 0;q.push(NULL);continue;}
            tempsum+=temp->val;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        ans = tempsum;
        
        return ans;
    }
};