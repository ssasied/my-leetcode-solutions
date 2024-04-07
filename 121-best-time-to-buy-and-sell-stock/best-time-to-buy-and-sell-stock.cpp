class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_min=prices[0];
        int max_dif=0;
        for(int i=1;i<prices.size();i++){
            current_min=min(current_min,prices[i]);
            max_dif=max(max_dif,prices[i]-current_min);  
        }
        return max_dif;
    }
};