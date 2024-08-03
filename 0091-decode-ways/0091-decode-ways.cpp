class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        // let dp[i] be num of ways to represent string till ith index
        vector<int> dp(n+1, 0);
        dp[0] = 1; // there is a way to represent empty string (null set).
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                string s1 = s.substr(j-1, i-j+1);
                if(s1[0] == '0' || s1.length() > 2) continue;
                int cnt = stoi(s1);
                if(cnt > 0 && cnt < 27) dp[i] += dp[j-1];
            }
        }
        return dp[n];
    }
};