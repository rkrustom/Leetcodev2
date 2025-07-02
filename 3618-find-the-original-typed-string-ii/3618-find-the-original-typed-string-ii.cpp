static const int MOD = 1000000007;
class Solution {
public:
    int possibleStringCount(string word, int k) {
    int n = word.size();
        vector<int> runs;
        runs.reserve(n);
        for (int i = 0, j; i < n; i = j) {
            j = i + 1;
            while (j < n && word[j] == word[i]) j++;
            runs.push_back(j - i);
        }
        int M = runs.size();

        long long total = 1;
        for (int r: runs) {
            total = (total * r) % MOD;
        }

        if (M >= k) {
            return (int)total;
        }


        int d = k - M;
        vector<int> dp(d), nxt(d), pref(d);
        dp[0] = 1;
        for (int r: runs) {
            int m = min(r - 1, d - 1);
            pref[0] = dp[0];
            for (int u = 1; u < d; u++) {
                pref[u] = pref[u - 1] + dp[u];
                if (pref[u] >= MOD) pref[u] -= MOD;
            }
            for (int u = 0; u < d; u++) {
                int v = pref[u];
                if (u - m - 1 >= 0) {
                    v = (v - pref[u - m - 1] + MOD) % MOD;
                }
                nxt[u] = v;
            }
            swap(dp, nxt);
        }
        long long bad = 0;
        for (int u = 0; u < d; u++) {
            bad = (bad + dp[u]) % MOD;
        }
        long long ans = (total - bad) % MOD;
        if (ans < 0) ans += MOD;
        return (int)ans;    
    }
};