/*
https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1/?category[]=Dynamic%20Programming&company[]=Google&page=1&query=category[]Dynamic%20Programmingcompany[]Googlepage1

You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.
In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.

Example 1:

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)
Example 2:

Input:
N = 4
A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum
value as 22(7 + 15)
*/

/*
================================================>
I have seen this question on codeforces also but that time i don't know anything about dp.
First thing about this problem that we can't think it greedly. It feels like greedy but we can't.
If we take it greedly than what we will do is we will check which is greater among front or back of remaining array and take that. but we didn't care 
about number coming to next after current front or back.

By DP APproach = >

i took two pointer one is s(start) and other is f (final), every time we will check if we take starting point there will be two case
we can increase start by 2 or decrease end by 1 and we will take minimum as maximum will be taken by opponent 
Similar from end side
*/


int dp[110][110];

int cal(int s,int f,int arr[]){
    if(s>f)return 0;
    if(dp[s][f]!=-1)return dp[s][f];
    
    int ans = 0;
    ans = max(ans,arr[s]+min(cal(s+1,f-1,arr),cal(s+2,f,arr)));
    ans = max(ans,arr[f]+min(cal(s+1,f-1,arr),cal(s,f-2,arr)));
    return dp[s][f] = ans;
}

long long maximumAmount(int arr[], int n) 
{
    memset(dp,-1,sizeof(dp));
    return ans = cal(0,n-1,arr);
}