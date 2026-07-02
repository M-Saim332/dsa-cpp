/*
Problem: Best Time to Buy and Sell Stock

Approach:
- Traverse the array only once.
-Imagning the everday as the selling day.
-At index 0,it can be served as buying day before it there must be a selling day.


Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int MP=0;//Maxprofit
        int bestbuy=prices[0];//Bestbuying day
        for (int i=1;i<n;i++)
        {
            if(prices[i]>bestbuy){
                MP=max(MP,prices[i]-bestbuy);

            }
        bestbuy=min(bestbuy,prices[i]);
        }
        return MP;
        
    }
};
