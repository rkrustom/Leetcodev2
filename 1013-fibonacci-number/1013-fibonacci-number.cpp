class Solution {
public:
/*
int fib(int n,vector<int>&dp){
    if(n<=1) return n;
    //step--->3 memozation
    if(dp[n]!=-1) return dp[n];
    //step--->2 first store the value then return 
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];

}*/
    int fib(int n) {        
   /*
   //step--->1 create a table to store the value of subproblem
    vector<int>dp(n+1,-1);
    int ans=fib(n,dp);
    return ans;
    */
//BOTTOM UP ---> TABULATION APPROACH
    // Handle the base cases explicitly
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];

    }
};