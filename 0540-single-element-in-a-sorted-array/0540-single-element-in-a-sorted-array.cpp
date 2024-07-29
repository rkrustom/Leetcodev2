class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    //video solution----->  https://www.youtube.com/watch?v=PzszoiY5XMQ
    //T.C------>O(n)
    // int ans=0;
    // int n=nums.size();
    // for(int i=0;i<n;i++){
    //     ans=ans^nums[i];
    // }  
    // return ans;  
  //Optimal solution
  int n=nums.size();
  int low=0,high=n-2;
  while(low<=high){
    int mid=(low + high)/2;
    if(nums[mid]==nums[mid^1]){
        low=mid+1;
    }
    else high=mid-1;
  }
  return nums[low];
    }
};