/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
*/

class Solution {
public:
    vector<int>fact(int A){
        vector<int>ans(A+1,1);
        for(int i =1;i<=A;i++)ans[i] = ans[i-1]*i;
        return ans;
    }
    string getPermutation(int A, int B) {
        vector<int>factorial = fact(A+1);
        vector<int>p(A+100,INT32_MAX);
        for(int i = 0;i<A;i++)p[i] = i+1;
        B--;
    
        for(int i = 0;i<A;i++){
            int per = B/factorial[A-(i+1)];
            swap(p[i],p[i+per]);
            if( B ==0)B=0;
            else B = B%factorial[A-(i+1)];
            sort(p.begin()+i+1,p.end());
        }
    
        string ans = "";
        for(int i=0;i<A;i++){ans+=to_string(p[i]);}
        return ans;
    }
};