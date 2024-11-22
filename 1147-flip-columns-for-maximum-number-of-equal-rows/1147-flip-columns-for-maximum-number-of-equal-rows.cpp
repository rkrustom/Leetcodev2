class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;

    for (const auto& row : matrix) {
        string normalizedPattern;
        for (int val : row) {
            normalizedPattern += (val == row[0]) ? '0' : '1';
        }
        patternCount[normalizedPattern]++;
    }
    int maxRows = 0;
    for (const auto& [pattern, count] : patternCount) {
        maxRows = max(maxRows, count);
    }
    return maxRows;
    }
};