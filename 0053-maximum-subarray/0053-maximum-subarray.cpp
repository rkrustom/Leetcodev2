class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    //Kadane's Algorithm
    //  int maxi=INT_MIN;
    //  int n=nums.size();
    //  int sum=0;
    //  for(int i=0;i<n;i++){
    //   sum=sum+nums[i];
    //   maxi=max(maxi,sum);
    //   if(sum<0) sum=0;
    //  }   
    //  return maxi;



   int sum=0;
   int maxi=INT_MIN;
   int n=nums.size();
    for(int i=0;i<n;i++){
     sum+=nums[i];
     if(sum>maxi) maxi=sum;
     if(sum<0) sum=0;
    }
     return maxi;
    }
};