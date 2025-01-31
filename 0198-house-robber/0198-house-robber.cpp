class Solution {
public:
    int solve(int i, vector<int>&nums,vector<int>&dp){
        //base case
        if(i>=nums.size()) return 0;
        int inc=0;
        int exc=0;
        if(dp[i]!=-1){
            return dp[i];
        }
        //including
        inc=nums[i]+solve(i+2,nums,dp);
        //excluding
        exc=solve(i+1,nums,dp);
        return dp[i]=max(inc,exc);

    }
    int rob(vector<int>& nums) {
        int i=0;
        int n=nums.size();
       vector<int>dp(n+1,-1);
       int ans= solve(i,nums,dp);
       return ans;
    }
};