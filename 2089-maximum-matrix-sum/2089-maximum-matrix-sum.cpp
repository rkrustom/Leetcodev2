class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    long long totalSum = 0; 
    int minAbsValue = INT_MAX;
    int negativeCount = 0; 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int value = matrix[i][j];
            totalSum += abs(value); 
            minAbsValue = min(minAbsValue, abs(value)); 
            if (value < 0) {
                negativeCount++; 
            }
        }
    }
    if (negativeCount % 2 != 0) {
        totalSum -= 2 * minAbsValue;
    }
    return totalSum;
    }
};