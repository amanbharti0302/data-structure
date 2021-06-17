/*
Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.
Example 1:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
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
void dfs(TreeNode *root,TreeNode *p,TreeNode *gp,int &ans){
    if(root==NULL)return;
    if(p!=NULL&&gp!=NULL&&(gp->val)%2==0)ans+=root->val;
    
    if(root->left)dfs(root->left,root,p,ans);
    if(root->right)dfs(root->right,root,p,ans);
    
}

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        dfs(root,NULL,NULL,ans);
        return ans;
    }
};