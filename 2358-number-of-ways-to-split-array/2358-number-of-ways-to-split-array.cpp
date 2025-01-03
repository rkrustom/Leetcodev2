class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
      int n = nums.size();
    int validSplitsCount = 0;
    long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);

    long long prefixSum = 0;

    for (int i = 0; i < n - 1; ++i) {
        prefixSum += nums[i];
        long long suffixSum = totalSum - prefixSum;
        if (prefixSum >= suffixSum) {
            validSplitsCount++;
        }
    }

    return validSplitsCount;   
    }
};