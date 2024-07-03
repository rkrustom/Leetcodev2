class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<=4) return 0;
        int ans1=nums[n-4]-nums[0];
        int ans2=nums[n-3]-nums[1];
        int ans3=nums[n-2]-nums[2];
        int ans4=nums[n-1]-nums[3];
        int sol1=min(ans1,ans2);
        int sol2=min(ans3,ans4);
        int sol=min(sol1,sol2);
        return sol;
    }
};