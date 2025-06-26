class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len = 0;
        long val = 0;
        int pow = 0;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];

            if (c == '0') {
                len++;  
            } 
            else {
                if (pow < 32) {  
                    long bitVal = 1L << pow;                    
                    if (val + bitVal <= k) {
                        val += bitVal;
                        len++;
                    }
                }
            }
            pow++;
        }
        return len;    
    }
};