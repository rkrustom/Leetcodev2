class Solution {
public:
    int solve(int i, int amount, vector<int>&coins,vector<vector<int>>&dp){
        int n=coins.size();
        //base case
        if(amount==0){
            return 0;
        }
        if(i>=n ){
            return 1e9;
        }
        // if(amount<coins[i]) return 1e9;
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
      int inc=1e9;
      int exc;
      if(amount>=coins[i])
      inc=1+solve(i,amount-coins[i],coins,dp);
      exc=solve(i+1,amount,coins,dp);
      return dp[i][amount]=min(inc,exc);
      


    }
    int coinChange(vector<int>& coins, int amount) {
        int i=0;
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(i,amount,coins,dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};