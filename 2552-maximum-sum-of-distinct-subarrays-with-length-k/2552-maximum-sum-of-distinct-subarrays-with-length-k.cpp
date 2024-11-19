class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    long long n = nums.size();
    if (k > n) return 0; 
    unordered_map<long long, long long> freq; 
    long long windowSum = 0, maxSum = 0;

    for (int i = 0; i < n; ++i) {
        freq[nums[i]]++;
        windowSum += nums[i];
        if (i >= k) {
            long long toRemove = nums[i - k];
            freq[toRemove]--;
            if (freq[toRemove] == 0) {
                freq.erase(toRemove);
            }
            windowSum -= toRemove;
        }
        if (freq.size() == k) {
            maxSum = max(maxSum, windowSum);
        }
    }

    return maxSum; 
    }
};