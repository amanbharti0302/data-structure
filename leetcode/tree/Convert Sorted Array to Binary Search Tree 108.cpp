// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of
// the two subtrees of every node never differ by more than 1.


//====> My approach
// As sorted array is given, isn't it a inorder traversal o a binary tree
//ofcourse , we can apply binary search algorithm to divide array in parts of equal half and each prt can be divided in same manner in further parts
//middle of that part will be root for a subpart
//left reamining part will be left subtree
//right remaining part will be right subtree

//===========================>code

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

TreeNode* cal(vector<int>& nums,int l,int r){
    if(l>r)return NULL;
    int mid = (l+r)/2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->right=cal(nums,mid+1,r);
    root->left=cal(nums,l,mid-1);
    return root;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0)return NULL;
        return cal(nums,0,nums.size()-1);
    };
};