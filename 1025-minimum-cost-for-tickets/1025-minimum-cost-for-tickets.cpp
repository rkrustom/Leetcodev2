class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int M=days.back(), d0=days[0];
        vector<int> dp(M+1, 0);
        for (int d=d0, i=0; d<=M; d++){
            if (d==days[i]){
                i++;
                dp[d]=min({ costs[0]+dp[max(d-1, 0)],
                    costs[1]+dp[max(d-7, 0)],
                    costs[2]+dp[max(d-30, 0)]
                });
            }
            else dp[d]=dp[d-1];
        }
        return dp[M];
    }
};