class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
      vector<string> groups;
        int n = s.size();
        int numGroups = (n + k - 1) / k; 
        
        for (int i = 0; i < numGroups; ++i) {
            int start = i * k;
            int len = min(k, n - start);
            string part = s.substr(start, len);
            if (len < k) {
                part.append(k - len, fill);
            }
            groups.push_back(part);
        }
        
        return groups;   
    }
};