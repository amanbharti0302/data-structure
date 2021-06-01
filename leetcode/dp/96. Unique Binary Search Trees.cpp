/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
==========================================================>>Approaches
There are two approaches to solve this problem 

1. Using Catalan series
    Total number of unique binary search trees of size n is the nth value of catalan series
    soln = cat(n);

2. Using Dynamic Programming
   for a binary search trees of size n there will be n nodes from 1 to n and all these nodes will become root in some case
   if k is root than to follow Bst all numbers smaller than k will be left to k and all numbers greater than k will be on right of k.
   on left ==> number of nodes = k-1
   on right ==> numbers of nodes = n-k
   using dp we will calculate for every size of bst from 1 to n
   for bst of size 1 and 0 answer will be 1 always ==>best case
   thus we can calculate for size 3 as in size 1 2 3 can be node than for every node we will calculatr answer and sum it.
*/

/////////////////////////1 . Catalan approach
int catalan(int n){
    int cat[n+1];
    cat[0]=cat[1]=1;
    for(int i=2;i<=n;i++){
        cat[i]=0;
        for(int j=0;j<i;j++)
        cat[i]=cat[i]+(cat[j]*cat[i-j-1]);
    }
    return cat[n];
}

class Solution {
public:
    int numTrees(int n) {
        return catalan(n);
    }
};

/////////////////////////2. Dp Approach
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0]=1;dp[1]=1;
        
        for(int i=2;i<=n;i++){
            int ans=0;
            for(int j=1;j<=i;j++){
                int left=j-1,right=i-j;
                ans+=(dp[left]*dp[right]);
            }
            dp[i]=ans;
        }
        
        return dp[n];
    }
};

//if we lool carefully both are same