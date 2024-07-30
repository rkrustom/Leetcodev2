class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // //first observation ---> longest prefix sum
        // int n=nums.size();
        // int index=-1;
        // for(int i=n-2;i>=0;i--){
        //     if(nums[i]<nums[i+1]){
        //         index=i;
        //         break;
        //     }
        // }
        // if(index==-1){
        //     reverse(nums.begin(),nums.end());
        //     return ;
        // }
        // //second observation----> grater than arr[i] but smaller one
        // else{
        // for(int i=n-1;i>=index;i--){
        //     if(nums[i]>nums[index]){
        //         swap(nums[i],nums[index]);
        //         //ramaining to handle the edge case
        //     }
        // }
        // }
        // //third observation----->place ramaining in sorted order or reverese it
        // reverse(nums.begin()+index+1,nums.end());
       int n = nums.size();
       int index = -1;
       
       // Find the largest index `index` such that nums[index] < nums[index + 1]
       for (int i = n - 2; i >= 0; i--) {
           if (nums[i] < nums[i + 1]) {
               index = i;
               break;
           }
       }

       // If no such index exists, reverse the entire array
       if (index == -1) {
           reverse(nums.begin(), nums.end());
           return; // No further processing needed
       }

       // Find the largest index `j` such that nums[index] < nums[j]
       for (int i = n - 1; i > index; i--) {
           if (nums[index] < nums[i]) {
               swap(nums[index], nums[i]);
               break;
           }
       }

       // Reverse the subarray from index + 1 to the end of the array
       reverse(nums.begin() + index + 1, nums.end()); 
        
    }
};