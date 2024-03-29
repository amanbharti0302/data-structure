/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:
The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1. 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>order(n+1,0);
        vector<int>inor(n+1,0);
        for(auto to:trust){
            inor[to[0]]++;
            order[to[1]]++;
        }
        for(int i=1;i<=n;i++)if(order[i]==n-1&&inor[i]==0)return i;
        return -1;
    }
};