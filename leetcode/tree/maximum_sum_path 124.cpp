//Here in this case we have to find maximum sum of path from any two node
//so what we do is for every node we get left maximum sum and right maximum sum using recursion
// after that there may be three case 
// 1. maximum path will come from left of that taken particular node and goes to right of that node
// 2. left path may contain -ve value so we start from that node excluding node and either we will go to right path of upward towards its parent.
// so answer will be maximum of left+rootvalue , right+rootvalue, left+right+rootvalue ,rootvalue;
  

int cal(TreeNode* root,int &res){
    if(root==NULL)return 0;
    int l = cal(root->left,res);
    int r = cal(root->right,res);
    
    res=max(res,max(root->val,l+r+root->val));
    res=max(res,l+root->val);
    res=max(res,r+root->val);
    
    return max(root->val,max(l+root->val,r+root->val));
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res= INT_MIN;
        cal(root,res);
        return res;
    }
};