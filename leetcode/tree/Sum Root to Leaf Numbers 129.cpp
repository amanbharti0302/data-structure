// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.

//very easy

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

int cal(TreeNode* root,int sum){
    if(root->left==NULL&&root->right==NULL)return sum*10+root->val;  
    int ans=0;
    if(root->left)ans+=cal(root->left,sum*10+root->val);
    if(root->right)ans+=cal(root->right,sum*10+root->val);
    return ans;
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        return cal(root,0);
    }
};