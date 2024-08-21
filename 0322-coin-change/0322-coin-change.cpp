class Solution{
	public:
	int solveRec(vector<int>&nums,int amount){
	    //base case
	    if(amount==0) return 0;
	    if(amount<0) return INT_MAX;
	    int mini=INT_MAX;
	    for(int i=0;i<nums.size();i++){
	        int ans=solveRec(nums,amount-nums[i]);
	        if(ans!=INT_MAX)
	        mini=min(mini,1+ans);
	        
	    }
	    return mini;
	    
	}
	
		int solvemem(vector<int>&nums,int amount,vector<int>&dp){
	    //base case
	    if(amount==0) return 0;
	    if(amount<0) return INT_MAX;
	    
	    //step---->3
	   if(dp[amount]!=-1) return dp[amount];

	    
	    int mini=INT_MAX;
	    for(int i=0;i<nums.size();i++){
	        int ans=solvemem(nums,amount-nums[i],dp);
	        if(ans!=INT_MAX)
	        mini=min(mini,1+ans);
	        
	    }
	    dp[amount]=mini;
	    return mini;
	    
	}
	
	
	
	int coinChange(vector<int>nums, int amount)
	{
	   // int ans=solveRec(nums,amount);
	   // if(ans==INT_MAX) return -1;
	   // return ans;
	   
	   int n=nums.size();
	   //step---->1
	   vector<int> dp(amount+1,-1);
	   int ans=solvemem(nums,amount,dp);
	   if(ans==INT_MAX) return -1;
	   return ans;
	}
};