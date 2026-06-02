class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n =prices.size();
       vector<int>arr(n,0);

       arr[0] = INT_MAX;

       for(int i = 1; i < n ; i++ )
       {
        arr[i] = min(arr[i-1],prices[i-1]);
       } 
       int profit = 0;

       for (int i = 0 ; i< n ;i++ )
       {
        int currprofit = prices[i] - arr[i];
        profit = max(currprofit,profit);
       }
       return profit;
    }
};