class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int>cntele;
        for(auto it:nums){
            cntele[it]++;
        }
        int sum=0;
        for(auto i:cntele){
            if(i.second==1){
                sum+=i.first;
            }
        }
        return sum;
    }
};