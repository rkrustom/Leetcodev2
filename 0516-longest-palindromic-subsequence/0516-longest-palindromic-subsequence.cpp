class Solution {
public:
    int solve(int ind1,int ind2,string &s,vector<vector<int>>&dp){
    //base case    
    if(ind1==ind2) return 1;
    if(ind1>ind2) return 0;

    if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
    }
    //logic
    if(s[ind1]==s[ind2]){
        return dp[ind1][ind2]=2+solve(ind1+1,ind2-1,s,dp);
    }
    else{
        return dp[ind1][ind2]=max(solve(ind1,ind2-1,s,dp),solve(ind1+1,ind2,s,dp));
    }
    }
    int longestPalindromeSubseq(string s) {
        int n=0;
        int m=s.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        int ans=solve(n,m-1,s,dp);
        return ans;
    }
};