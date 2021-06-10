/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0,0,inorder.size()-1,preorder,inorder);
    }
    
    TreeNode* helper(int preind,int instrt,int inend,vector<int>& preorder, vector<int>& inorder){
        if(preind>=preorder.size()||instrt>inend)return NULL;
        int rootpos = 0;
        
        for(int i = instrt;i<=inend;i++){
            if(inorder[i]==preorder[preind]){rootpos = i;break;}
        }
        
        TreeNode * root = new TreeNode(preorder[preind]);
        
        root->left = helper(preind+1,instrt,rootpos-1,preorder,inorder);
        root->right = helper(preind+(rootpos-instrt)+1,rootpos+1,inend,preorder,inorder);
        
        return root;
    }
    
};