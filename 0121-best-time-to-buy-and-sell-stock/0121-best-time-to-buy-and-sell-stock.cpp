class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n=prices.size();
     int mini=prices[0];
     int maxi=prices[0]-mini;
     for(int i=0;i<n;i++){
        if(mini>prices[i]) mini=prices[i];
        if(maxi<prices[i]-mini)
        maxi=prices[i]-mini;
     }  
     return maxi;
    }
};