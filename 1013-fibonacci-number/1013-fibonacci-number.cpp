class Solution {
public:
int fib(int n,vector<int>&dp){
    if(n<=1) return n;
    //step--->3 memozation
    if(dp[n]!=-1) return dp[n];
    //step--->2 first store the value then return 
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];

}
    int fib(int n) {        
   //step--->1 create a table to store the value of subproblem
    vector<int>dp(n+1,-1);
    int ans=fib(n,dp);
    return ans;

    }
};