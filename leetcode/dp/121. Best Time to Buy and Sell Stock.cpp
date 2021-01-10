/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

===========================================================>>>>
Only thing to observe in this question is that if we move right and we find smaller number than when we find a number bigger than precing number 
it will be more bigger to this number so why not update currnumber to to this number abd when we find next number greater than current number
than we take maxm till obtained answer
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        int maxm =0,currpr=prices[0];
        for(int i=1;i<prices.size();i++){
            if(currpr<prices[i])maxm = max(maxm,prices[i]-currpr);
            else currpr = prices[i];
        }
        return maxm;
    }
};