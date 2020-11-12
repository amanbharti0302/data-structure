//There are two methods of solving this problem
//1. using DP
//2. using catalan series formula  ( Cn = (2n)!/((n+1)!n!) ) 

//1.DP
//IF tree has only 1 node than 1 combination is possibe
//If tree has 2 node then 2 combination is possible

//Now if tree has n nodes
//Once every node can be root
//let suppose xth node become root
// then x-1 nodes will be left of x and n-x will be on right
//now left child tree of x-1 tree will be a independet tree and right n-x will be also
//number of diiferent bst will be product of (left *right) part
//similarly left and right part can be calculated using dp approach

// 1, 1, 2, 5, 14, 42, 132, 429.............. positions are 0 1 2 3 ....


/////////////////////////////////////////////using dynamic programming
int catalan(int n){
    int dp[n+1];
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=0;
        for(int j=0;j<i;j++)dp[i]=dp[i]+(dp[j]*dp[i-j-1]);
    }
    return dp[n];
}

class Solution {
public:
    int numTrees(int n) {return catalan(n);}
};

