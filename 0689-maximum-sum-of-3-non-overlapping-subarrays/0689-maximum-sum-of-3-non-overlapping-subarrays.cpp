class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
       int n = nums.size();
    vector<long> sum(n - k + 1, 0); 
    long currentSum = 0;
    for(int i = 0; i < n; ++i){
        currentSum += nums[i];
        if(i >= k){
            currentSum -= nums[i - k];
        }
        if(i >= k -1){
            sum[i - k +1] = currentSum;
        }
    }

    vector<int> left(n - k +1, 0);
    vector<int> right(n - k +1, n - k);

    int best = 0;
    for(int i =0; i < sum.size(); ++i){
        if(sum[i] > sum[best]){
            best = i;
        }
        left[i] = best;
    }
    best = sum.size() -1;
    for(int i = sum.size()-1; i >=0; --i){
        if(sum[i] >= sum[best]){ 
            best = i;
        }
        right[i] = best;
    }

    vector<int> result(3, -1);
    long maxTotal = 0;
    for(int j = k; j < sum.size() -k; ++j){
        int i = left[j -k];
        int l = right[j +k];
        long total = sum[i] + sum[j] + sum[l];
        if(total > maxTotal){
            maxTotal = total;
            result = {i, j, l};
        }
    }

    return result;   
    }
};