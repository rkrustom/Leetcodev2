class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count1=0;
       int  count1max=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                // count1max=max(count1max,count1);
                count1=0;
            }
            if(nums[i]==1){
                count1++;
            }
            if(count1>count1max) count1max=count1;
        }
        return count1max;
    }
};