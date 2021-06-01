/*
You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Example 1:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
*/

/*


I am writing my feeling here because i know nobody can see this.
Anybody can scold me and i don't care about it.But u matters for me.
I know i am nothing for u and i don't matter to u.I accept my mistake of loving and caring.

I have not intention to make u feel irritated.
If i did then sorry.


*/



TreeNode *f,*s;
TreeNode *last;

void inorder(TreeNode *root){
    if(root==NULL)return;
    if(root->left!=NULL)inorder(root->left);
    if(last->val>root->val&&f==NULL)f=last,s=root;
    else if(last->val>root->val)s=root;
    last=root;
    if(root->right!=NULL)inorder(root->right);
}

class Solution {
public:
    void recoverTree(TreeNode* root) {
        f=NULL,s=NULL;
        last = root;
        while(last->left)last=last->left;
        inorder(root);
        if(f&&s)
        swap(f->val,s->val);
        
    }
};
