class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int currBuy=INT_MIN,currSell=0;
        for(int i=0;i<prices.size();i++){
            currBuy = max(currBuy, currSell - prices[i]);
            currSell = max(currSell, currBuy+prices[i]-fee);
        }
        return currSell;
        
    }
};