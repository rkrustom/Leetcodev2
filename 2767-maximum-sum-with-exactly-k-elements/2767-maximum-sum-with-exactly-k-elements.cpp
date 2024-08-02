class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // int sum=0;
        // for(int i=0;i<k;i++){
        //    sum=sum+nums[n-1];
        //    nums[n-1]++;
        // }
        // return sum;
        int max_e=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
         max_e=max(max_e,nums[i]);
        }
       for(int i=0;i<k;i++){
         sum+=max_e;
         max_e++;
       }
       return sum;
    }
};