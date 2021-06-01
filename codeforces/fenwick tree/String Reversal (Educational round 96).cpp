/*
You are given a string s. You have to reverse it — that is, the first letter should become equal to the last letter before the reversal, the second letter should become equal to the second-to-last letter before the reversal — and so on. For example, if your goal is to reverse the string "abddea", you should get the string "aeddba". To accomplish your goal, you can swap the neighboring elements of the string.
Your task is to calculate the minimum number of swaps you have to perform to reverse the given string.
Input
The first line contains one integer n (2≤n≤200000) — the length of s.
The second line contains s — a string consisting of n lowercase Latin letters.

Output
Print one integer — the minimum number of swaps of neighboring elements you have to perform to reverse the string.

Examples

5
aaaza
2

6
cbaabc
0

9
icpcsguru
30

======================>Use fenwick tree 
*/

////////////////////    I am dumb    /////////////////////////////////
//Coded by Aman Bharti (ECE 2k18) Nit Patna
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long int
#define mod 1000000007

int fen[300000];
int n;
int update(int idx){
  for(;idx<n;idx=idx|(idx+1))fen[idx]+=1;      //index of region increased by 1
}

int prsum(int idx){
  int res =0;
  for(;idx>=0;idx=(idx&(idx+1))-1)res+=fen[idx];
  return res;
}

int getindsum(int l,int r){return prsum(r)-prsum(l-1);}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 
  // assert(freopen("soln.in","r",stdin));
  // assert(freopen("soln.out","w",stdout));
 
  int test=1;
  //cin>>test;
  //test =1;

  while(test-->0){
    cin>>n;
    string s;
    cin>>s;

    vector<int>pos[27];
    int cnt[27]={0};
    for(int i=0;i<n;i++)pos[s[i]-'a'].push_back(i);
    reverse(s.begin(),s.end());
    int res =0;

    for(int i=0;i<n;i++){
      int idx = pos[s[i]-'a'][cnt[s[i]-'a']++];
      res+=idx+getindsum(idx,n-1)-i;   //getindsum is record of increased index
      update(idx);              //now update the index from i+1 to obtained dist point by 1 as there index increased by 1 so that we can keep 
                                //record how many elements ahead of that index goes back to that position
    }

    cout<<res<<endl;
  }
  return 0;
}


