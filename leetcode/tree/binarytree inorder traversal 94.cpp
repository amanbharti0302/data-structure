//very easy iterative approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>sol;
        TreeNode *curr = root;
        while(curr!=NULL||!s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            curr = s.top();
            s.pop();
            sol.push_back(curr->val);
            curr=curr->right;
        }
        return sol;
    }
    
};