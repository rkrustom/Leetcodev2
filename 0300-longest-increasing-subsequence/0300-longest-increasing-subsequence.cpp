class Solution {
public:
    int solve(int i,int prev,vector<int>&nums,vector<vector<int>>&dp){

   //base case
   if(i>=nums.size()) return 0;
   //condition for include
   int inc=0;
   int exc=0;
   if(dp[i][prev+1]!=-1){
    return dp[i][prev+1];
   }
   if(prev==-1||nums[i]>nums[prev]){
    inc=1+solve(i+1,i,nums,dp);
   }
   exc=solve(i+1,prev,nums,dp);
    return dp[i][prev+1]=max(exc,inc);

    }
    int lengthOfLIS(vector<int>& nums) {
        int i=0;
        int prev=-1;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       int ans= solve(i,prev,nums,dp);
       return ans;
    }
};