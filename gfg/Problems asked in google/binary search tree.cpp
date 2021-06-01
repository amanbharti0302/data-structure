/*.......CODEFORCES......*/
//Coded by Aman Bharti (ECE 2k18) Nit Patna
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define end cout<<endl

class node{
  public:
  int data;
  node *left,*right;

  node(){
    data=0;
    left=right=NULL;
  }

  node(int val){
    data=val;
    left=right=NULL;
  }
};

void in_order(node *root){
  if(root==NULL)return;
  in_order(root->left);
  cout<<root->data<<" ";
  in_order(root->right);
}

void pre_order(node *root){
  if(root==NULL)return;
  cout<<root->data<<" ";
  pre_order(root->left);
  pre_order(root->right);
}

void post_order(node * root){
  if(root==NULL)return;
  post_order(root->left);
  post_order(root->right);
  cout<<root->data<<" ";
}

node *insert_bst(node *root,int data){
  if(root==NULL)return new node(data);
  else if(data<=root->data)root->left = insert_bst(root->left,data);
  else root->right = insert_bst(root->right,data);
  return root;
}

node *get_max_leftSubtree(node *root){
  while(root->right!=NULL){root=root->right;}
  return root;
}

node *delete_bst(node *root ,int data){
  if(root==NULL)return root;
  else if(data<root->data) root->left = delete_bst(root->left,data);
  else if(data>root->data) root->right = delete_bst(root->right,data);
  else{
    if(root->left==NULL&&root->right==NULL){delete(root);root=NULL;}
    else if(root->left == NULL){
      node * temp = root;
      root = root->right;
      delete(temp);
    }
    else if(root->right==NULL){
      node * temp = root;
      root = root->left;
      delete(temp);
    }
    else{
      node * temp = get_max_leftSubtree(root->left);
      root->data = temp->data;
      root->left = delete_bst(root->left,temp->data);
    }
  }

  return root;
}

node *create_bst(vector<int>ar){
  node * root = NULL;
  for(auto data:ar){root = insert_bst(root,data);}
  return root;
}



int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // assert(freopen("soln.in","r",stdin));
  // assert(freopen("soln.out","w",stdout));
  
  int test = 1;
  //cin>>test;

  while(test--){
    //Question 1(a) draw bst of {36, 22, 10, 44, 42}
    node *root = create_bst({36, 22, 10, 44, 42});

    cout<<"Q. 1(a) Inorder traversal"<<endl;
    in_order(root);
    cout<<endl<<endl;

    //Question 1(b) do insertion of {16, 25, 3, 23, 24}
    //As insertion process is same as creation of bst
    cout<<"Q. 1(b)"<<endl;
    vector<int>data_to_insert = {16, 25, 3, 23, 24};
    for(auto data:data_to_insert)root = insert_bst(root,data);
    cout<<"Inorder traverse after insertion of 16,25,3,23,24 in BST :"<<endl;
    in_order(root);
    cout<<endl<<endl;

    cout<<"Q. 1(c), 1(e)"<<endl;
    vector<int>to_delete({42,23,22});
    for(auto data:to_delete)root = delete_bst(root,data);
    cout<<"Inorder traverse after deleteion of 42,23,22 :"<<endl;
    in_order(root);
    cout<<endl;

    cout<<"Postorder traverse after deleteion of 42,23,22 :"<<endl;
    post_order(root);
    cout<<endl;

    cout<<"Preorder traverse after deleteion of 42,23,22 :"<<endl;
    pre_order(root);
    cout<<endl;

  }
  cerr<<endl<<"Run Time: "<<(clock() * 1000. / CLOCKS_PER_SEC)<<" ms"<<endl;
  return 0;
}
