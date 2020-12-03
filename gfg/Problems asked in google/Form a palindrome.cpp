/*
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:
Print the minimum number of characters.
Constraints:
1 ≤ T ≤ 50
1 ≤ S ≤ 40
Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3

==========================================>>
I solved after takin hint.
we will do recursive approach and apply memoization here

take two pointer left (l) and right (r)
if(s[left]==s[right])than increase left by 1 or decrease right by 1
else we have two condition either we increse left by 1 or decrease right by 1
we will take best of both condition
*/

#include <bits/stdc++.h>
using namespace std;

string s;
int dp[100][100];

int cal(int l,int r){
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];   
    if(s[l]==s[r])return dp[l][r] = cal(l+1,r-1);
    return dp[l][r] = min(cal(l+1,r),cal(l,r-1))+1;
}

int main() {
	int test;
	cin>>test;
	while(test-->0){
	    memset(dp,-1,sizeof(dp));
	    cin>>s;
	    cout<<cal(0,s.length()-1)<<endl;
	}
	return 0;
}