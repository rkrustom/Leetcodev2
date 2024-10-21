class Solution {
public:
    int maxUniqueSplit(string s) {
          unordered_set<string> seen;  // To store unique substrings
        return backtrack(s, 0, seen);  // Call the recursive backtracking function
    }

    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        if (start == s.size()) {
            return 0; 
        }
        
        int maxSplits = 0; 
        string currentSubstring;  
        for (int i = start; i < s.size(); ++i) {
            currentSubstring += s[i];
            if (seen.find(currentSubstring) == seen.end()) {
                seen.insert(currentSubstring);
                int splits = 1 + backtrack(s, i + 1, seen);
                maxSplits = max(maxSplits, splits);               
                seen.erase(currentSubstring);  
            }
        }
        
        return maxSplits;
    }
};