class Solution {
public:
    double minimumAverage(vector<int>& nums) {
    vector<double> averages;
    int n = nums.size();
    
    for (int i = 0; i < n / 2; ++i) {
        auto minElement = min_element(nums.begin(), nums.end());
        auto maxElement = max_element(nums.begin(), nums.end());
        
        double average = (*minElement + *maxElement) / 2.0;
        
        averages.push_back(average);
        nums.erase(minElement);
        maxElement = std::max_element(nums.begin(), nums.end()); 
        nums.erase(maxElement);
    }
    
    double minAverage = *std::min_element(averages.begin(), averages.end());
    return minAverage;
    }
};