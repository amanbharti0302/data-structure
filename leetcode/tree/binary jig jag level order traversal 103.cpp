//Given a binary tree, return the zigzag level order traversal of its nodes' values. 
//(ie, from left to right, then right to left for the next level and alternate between).
//    3
//   / \
//  9  20
//    /  \
//   15   7

////////////////////////=====>sol to be printed
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

//===> my approach 
//As for breadth first search we uses queue data structure and here also we will do same like BFS
//we will push a extra null with root
//during poping whenever we get a null it means it is last point of that level
//On encountring null what we do is we will check that whether it is last level or not 
// to check this we will pop null and check if queue is empty than it is last level and we will break the loop
// else we will push a another null so that we can identify when next level is going to end
// using a bool we can altenatively insert left to right and right to left

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool righttoleft =false;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);    //extra null to identify end of 1st level
        
        vector<vector<int>>sol;
        vector<int> temp;
        
        while(!q.empty()){
            TreeNode* tp = q.front();
            q.pop();
            
            if(tp==NULL){                                       //end of a level identified
                if(temp.size()>0&&righttoleft==false){
                    sol.push_back(temp);
                    righttoleft=true;
                }
                else if(temp.size()>0&&righttoleft==true){
                    reverse(temp.begin(),temp.end());
                    sol.push_back(temp);
                    righttoleft=false;
                }
                temp.clear();
                while(q.front()==NULL)q.pop();
                if(q.empty())break;
                else q.push(NULL);
            }
            if(tp==NULL)continue;
            temp.push_back(tp->val);
            
            if(tp->left)q.push(tp->left);
            if(tp->right)q.push(tp->right);
        }
        
        if(temp.size()>0&&righttoleft==true){
            reverse(temp.begin(),temp.end());
            sol.push_back(temp);
        }
        else if(temp.size()>0&&righttoleft==false){
            sol.push_back(temp);
        }
        
        return sol;
    }
};