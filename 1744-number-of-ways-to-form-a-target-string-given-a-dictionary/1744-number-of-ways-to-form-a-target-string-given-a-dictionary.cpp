typedef long long ll;
const int MOD = 1e9 + 7;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
     int N = words.size();
    if(N == 0) return 0;
    int L = words[0].size();
    int M = target.size();
    if(M > L) return 0;
    vector<vector<int>> count(L, vector<int>(26, 0));
    for(auto &word : words){
        for(int k = 0; k < L; ++k){
            char c = word[k];
            count[k][c - 'a'] += 1;
        }
    }
    vector<int> dp(M +1, 0);
    dp[0] = 1;   
    for(int k = 0; k < L; ++k){
        for(int i = M-1; i >=0; --i){
            if(i < M){
                char c = target[i];
                int c_idx = c - 'a';
                if(count[k][c_idx] >0){
                    dp[i+1] = (dp[i+1] + (int)(((ll)dp[i] * count[k][c_idx]) % MOD)) % MOD;
                }
            }
        }
    }   
    return dp[M];   
    }
};