//Given a binary tree, determine if it is height-balanced.

//==>my approach
// we can easily find maximum depth of any part of subtree
//if in any subtree diffrence between maximum depth of left and right subtree exceeds 1 than make boolean false
//else continue

//==============>my code

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
int cal(TreeNode *root,bool &ch){
    if(root==NULL){return 0;}
    int l =cal(root->left,ch);
    int r = cal(root->right,ch);   
    if(abs(r-l)>1)ch=false;
    return max(l,r)+1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        bool ch=true;
        cal(root,ch);
        if(ch==false)return false;
        return true;
    }
};