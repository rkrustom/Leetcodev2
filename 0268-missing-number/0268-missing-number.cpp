class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
    //    int n=nums.size();
    //    int flag=0;
    //    for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //       if(nums[j]!=i)
    //       flag=i;
    //     }
        
    //    }
    //    if(flag==0) return n+1;
    //    else
    //    return flag;
    int n=nums.size();
    int sum=(n*(n+1))/2;
    int sum2=0;
    for(int i=0;i<n;i++){
   sum2+=nums[i];
    }
    int missing=sum-sum2;
    return missing;

    }
};