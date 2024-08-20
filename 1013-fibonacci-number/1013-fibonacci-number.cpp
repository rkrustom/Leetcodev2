class Solution {
public:
int fib(int n,vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];

    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];

}
    int fib(int n) {        
    // if( n==0) return 0;
    // if(n==1) return 1;
    // else return fib(n-1)+fib(n-2);
    vector<int>dp(n+1,-1);
    int ans=fib(n,dp);
    return ans;

    }
};