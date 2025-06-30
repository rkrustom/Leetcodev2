class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxLength = 0;

        for (int num : nums) {
            count[num]++;
        }
        for (auto& [key, val] : count) {
            if (count.find(key + 1) != count.end()) {
                maxLength = max(maxLength, val + count[key + 1]);
            }
        }

        return maxLength;
 
    }
};