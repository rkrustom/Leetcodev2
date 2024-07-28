class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=-1,end=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                start=i;
            }
        }
        for(int j=n-1;j>=0;j--){
            if(nums[j]==target)
            end=j;
        }
        return {end,start};
    }
};