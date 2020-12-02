/*
//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1/?category[]=Dynamic%20Programming&company[]=Google&page=1&query=category[]Dynamic%20Programmingcompany[]Googlepage1#

//Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Example 1:

Input:
N = 2, K = 10
Output: 4
Example 2:

Input:
N = 3, K = 5
Output: 3

//=============================> My Approach
This is a standard question of matrix chain multiplication
Best case :
if(no of floor is 0 then worst case minm step will be 0 as there is no floor)
if(no of floor is 1 then if no of egg is greater than 0 then in worst case we can find req. floor in 1 step)
if(no of egg is 0 then it makes no sense as we have not zero)
if(no of egg is 1 then worst case check will be going through every floor starting from bottom floor so no of floor will be answer)

now for every floor there will be two option if egg breaks then we have to check floors lower than that floor
and if egg do not break than we will have to check all floor that is above that floor.

thus there will be a floor from where it will give minimum steps i.e we don't know the floor from which we should start 
so we will go throgh loop and check every floor and take that floor which will give minimum. 
*/

int dp[50][100];

int cal(int n,int k){
    if(n==1||k==1||n==0)return k;
    if(dp[n][k]!=-1)return dp[n][k];
    int ans = INT_MAX;
    for(int i=1;i<=k;i++){ans = min(ans,max(1+cal(n,k-i),1+cal(n-1,i-1)));}
    return dp[n][k] = ans;
}

int eggDrop(int n, int k) 
{
    memset(dp,-1,sizeof(dp));
    return cal(n,k);
}