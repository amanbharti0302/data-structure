/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       return helper(postorder.size()-1,0,inorder.size()-1,inorder,postorder);
    }
    
    TreeNode * helper(int postind,int instrt,int inend,vector<int>& inorder,vector<int>& postorder){
        if(postind<0||instrt>inend)return NULL;
        
        TreeNode * root = new TreeNode(postorder[postind]);
        
        int rootpos = postorder.size()-1;
        
        for(int i= instrt;i<=inend;i++){
            if(inorder[i]==root->val){rootpos = i;break;}
        }
        
        root->left = helper(postind-(inend-rootpos)-1,instrt,rootpos-1,inorder,postorder);
        root->right = helper(postind-1,rootpos+1,inend,inorder,postorder);
        
        return root;
    }
    
};