class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //left pointer and right pointer
        int buy = 0;
        int sell = 1;

        int maxProfit = 0;
        //while the sell price is still within bounds       
        while(sell < prices.size()){
            //if we can buy for less than what we sell (aka profit)
            if(prices[buy] < prices[sell]){
                //calculate Current profit
                int currentProfit = prices[sell] - prices[buy];
                //find the max between the current and max profit and set it to the max
                maxProfit = max(maxProfit, currentProfit);
            } else {
                //if we cant make a profit we set buy = sell because that means
                //we found a new low price
                buy = sell;
            }
            //increase the right pointer regardless
            sell++;
        }
        return maxProfit;
    }
};