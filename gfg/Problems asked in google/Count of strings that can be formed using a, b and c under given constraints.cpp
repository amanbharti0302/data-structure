/*
https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0/?category[]=Dynamic%20Programming&company[]=Google&problemStatus=unsolved&page=1&query=category[]Dynamic%20Programmingcompany[]GoogleproblemStatusunsolvedpage1

Given a length n, count the number of strings of length n that can be made using ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the length of the string.

Output:
Output the count of the strings that can be formed under the given constraint.

Constraints:

1<= T <=100
1<= N <=1000

after reading internet soln i did this question.
1 if all the characters are a's
N if one character is B
N if one character is C
N(N-1) if one character is B and 1 character is C
N(N-1)/2 if Two characters are C
N(N-1)(N-2)/2 if one character is B and 2 characters are C
So the sum of all the above equations are
1+N+N+N(N-1)+N(N-1)/2+N(N-1)(N-2)/2
1+2*N+N(N-1) [1+1/2+(N-2)/2]
1+2*N+N(N-1)(N+1)/2
*/


#include <bits/stdc++.h>
using namespace std;

int dp[1005];

int cal(int n){
    return 1+(2*n)+((n*(n-1)*(n+1))/2);
}

int main() {
    dp[1]=3;
    dp[2]=6;
    dp[3]=19;
    
    for(int i=4;i<=1000;i++)
    dp[i] = cal(i);
        
    
    int test;
    cin>>test;
    while(test-->0){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
	return 0;
}