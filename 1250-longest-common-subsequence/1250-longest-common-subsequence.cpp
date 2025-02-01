class Solution {
public:
    int solve(int index1,int index2,string &s1, string &s2,vector<vector<int>>&dp){
    //base case
    if(index1<0||index2<0) return 0;

    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }
    //logic
    if(s1[index1]==s2[index2]){
     return dp[index1][index2]=1+solve(index1-1,index2-1,s1,s2,dp);
    }
    else{
        return dp[index1][index2]=max(solve(index1-1,index2,s1,s2,dp),solve(index1,index2-1,s1,s2,dp));
    }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=solve(n-1,m-1,text1,text2,dp);
        return ans;
    }
};