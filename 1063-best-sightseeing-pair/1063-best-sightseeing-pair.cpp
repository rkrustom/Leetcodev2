class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
    int max_val = values[0] + 0;
    int max_score = INT32_MIN;
    for(int j = 1; j < values.size(); j++) {
        int current_score = max_val + (values[j] - j);
        if(current_score > max_score) {
            max_score = current_score;
        }
        max_val = max(max_val, values[j] + j);
    }    
    return max_score;  
    }
};