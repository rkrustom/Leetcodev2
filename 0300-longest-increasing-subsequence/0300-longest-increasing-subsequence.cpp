class Solution {
public:
     int solve(int i,int prev,vector<int>& nums,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        int inc = 0;
        int exc=0;
     if(dp[i][prev+1]!=-1){
      return dp[i][prev+1];
     }

        if(prev==-1||nums[i]>nums[prev]){
            inc = 1 + solve(i+1,i,nums,dp);
        }
        exc=solve(i+1,prev,nums,dp);
        return dp[i][prev+1] = max(inc,exc);
     }
    int lengthOfLIS(vector<int>& nums) {
        int i=0;
        int prev=-1;
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solve(i,prev,nums,dp);   
    }
};