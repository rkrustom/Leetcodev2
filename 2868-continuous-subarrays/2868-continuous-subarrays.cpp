class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
         int n = nums.size();
    long long result = 0;
    deque<int> maxDeque, minDeque;

    int left = 0; 

    for (int right = 0; right < n; ++right) {
        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);
        while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
            minDeque.pop_back();
        }
        minDeque.push_back(right);
        while (!maxDeque.empty() && !minDeque.empty() &&
               abs(nums[maxDeque.front()] - nums[minDeque.front()]) > 2) {
            if (maxDeque.front() == left) maxDeque.pop_front();
            if (minDeque.front() == left) minDeque.pop_front();
            left++;
        }
        result += (right - left + 1);
    }

    return result;
    }
};