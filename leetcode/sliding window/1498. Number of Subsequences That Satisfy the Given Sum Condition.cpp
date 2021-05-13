/*
Given an array of integers nums and an integer target.
Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.
Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
Example 2:

Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
Example 3:

Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them don't satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
Example 4:

Input: nums = [5,2,4,1,7,6,8], target = 16
Output: 127
Explanation: All non-empty subset satisfy the condition (2^7 - 1) = 127

*/

class Solution {
public:
    int mod  = 1e9+7;
    
    int power(long long a,long long b){
        long long res = 1;
        while(b>0){
            if(b&1)res = res*a;
            res = (res+mod)%mod;
            a = (a*a+mod)%mod;
            b>>=1;
        }
        return (res+mod)%mod;
    }
    
    int numSubseq(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        int ans = 0;
        
        int p1 = 0,p2 = a.size()-1;
        
        while(p1<=p2){
            if(a[p1]+a[p2]>target){p2--;continue;}
            else {
                ans+=power(2,p2-p1);
                ans = ans%mod;
                p1++;
            }
        }
        
        return ans;
    }
};


//2^(n-1)