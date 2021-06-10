/*
A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
Example 1:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
Example 2:

Input: n = 1, primes = [2,3,5]
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        long long int a[n+2];
        priority_queue<long long int,vector<long long int>,greater<>> pq;
        pq.push(1);
        long long int ind = 0;
        
        while(1){
            if(ind>=n||pq.empty())break;
            a[ind++] = pq.top();
            long long int temp = pq.top();
            pq.pop();
            
            for(long long int x:primes){
                pq.push(x*temp);
            }
            
            while(!pq.empty()&&pq.top()==temp)pq.pop();
        }
        
        
        return a[n-1];
    }
};