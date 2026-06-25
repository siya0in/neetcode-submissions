class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit= 0;
        int minPrice=prices[0];

        for(int i=0;i<prices.size();i++){
            int profit= prices[i]-minPrice;
            maxprofit = max(profit, maxprofit);
            minPrice= min(minPrice, prices[i]);
        }
        return maxprofit;
    }
};
