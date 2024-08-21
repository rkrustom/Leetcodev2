class Solution {
public:
//   int solve(vector<int>&cost,int n){
//   //base case
//   if(n==0) return cost[0];
//   if(n==1) return cost[1];
//   int ans=cost[n]+min(solve(cost,n-1),solve(cost,n-2));
//   return ans;
//   }
   int solve2(vector<int>&cost,int n, vector<int>&dp){
    //base case
    if(n==0) return cost[0];
    if(n==1) return cost[1];
    //step-->3
    if(dp[n]!=-1) return dp[n];
    //step--->2
     dp[n]=cost[n]+min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
    return dp[n];
   }

    int minCostClimbingStairs(vector<int>& cost) {
    //    int n=cost.size();
    //    int sol=min(solve(cost,n-1),solve(cost,n-2));
    //    return sol;

    int n=cost.size();
    vector<int>dp(n+1,-1);
    int sol=min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
    return sol;
    }
};