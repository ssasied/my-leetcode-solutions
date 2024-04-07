class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)return 0;
        int current_min=prices[0];
        int sum=0;
        for(int i=1;i<prices.size()-1;i++){
            if(prices[i]>current_min)
                sum+=prices[i]-current_min;
            current_min=min(prices[i],prices[i+1]);
        }
        if(prices[prices.size()-1]>prices[prices.size()-2])sum+=prices[prices.size()-1]-prices[prices.size()-2];
        return sum;
    }
};