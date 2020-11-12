//In this question we have to check whether a given bst is valid or not
//my first approach which comes to mu mind is if we do inorder traversal of bst , we should get a sorted array
//using inorder travesal and storing in a vector and after that we can check whether the vector is sorted or not
//by this approach we can check validity in o(n) t.c and o(n) s.c


vector<int>a;
void cal(TreeNode* root){
    if(root==NULL)return;
    cal(root->left);
    a.push_back(root->val);
    cal(root->right);
}


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        a.clear();
        if(root==NULL)return true;
        cal(root);
        
        for(int i=0;i<a.size()-1;i++){
            if(a[i]>=a[i+1])return false;
        }
        return true;
    }
};


