class Solution {
public:
    int maximumLength(string s) {
    int n = s.length();
    unordered_map<string, int> freq; 
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        string special = "";
        for (int j = i; j < n; ++j) {
            if (s[j] != c) break; 
            special += c;
            freq[special]++;
        }
    }
   
    int maxLength = -1;
    for (const auto& entry : freq) {
        if (entry.second >= 3) {
            int len = entry.first.length();
            maxLength = max(maxLength, len);
        }
    }    
    return maxLength;
    }
};