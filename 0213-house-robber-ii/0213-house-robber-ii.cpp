class Solution {
public:
   int solve2(int i,vector<int>&nums,vector<int>&dp2){
    int n=nums.size();
        //base case
        if(i>=n) return 0;
        int inc=0;
        int exc=0;
        if(dp2[i]!=-1)
        return dp2[i];
        //including 
        inc=nums[i]+solve2(i+2,nums,dp2);
        //excluding
        exc=solve2(i+1,nums,dp2);
      return dp2[i]=max(inc,exc);
        
    }

    int solve1(int i,vector<int>&nums,vector<int>&dp1){
        //base case
        int n=nums.size();
        if(i>=n-1) return 0;
        int inc=0;
        int exc=0;
        if(dp1[i]!=-1){
            return dp1[i];
        }
        //including 
        inc=nums[i]+solve1(i+2,nums,dp1);
        //excluding
        exc=solve1(i+1,nums,dp1);
      return dp1[i]=max(inc,exc);
        
    }
    int rob(vector<int>& nums) {
      int n=nums.size();
      if(n==1) return nums[0];
      vector<int>dp1(n+1,-1);
      vector<int>dp2(n+2,-1);
       int i=0;
       int ans1=solve1(i,nums,dp1);
       int j=1;
       int ans2=solve2(j,nums,dp2);
       return max(ans1,ans2);

    }
};