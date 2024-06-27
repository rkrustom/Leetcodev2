class Solution {
public:
   int calcncr(int r,int c){
     long long res=1;
    for(int i=0;i<c;i++){
        res=res*(r-i);
        res=res/(i+1);
    }
    return res;
   }
    vector<int> getRow(int rowIndex) {
      vector<int> v;
      v.push_back(1);//pushing first element 1
      for(int i=1;i<=rowIndex;i++){
      long long ans=calcncr(rowIndex,i);  
       v.push_back(ans);
      }
      return v;
    }
};