class Solution {
public:
    void reverseString(vector<char>& s) {
    //  reverse(s.begin(),s.end());
    int n=s.size();
    int i=0,j=n-1;
    while(i<=j){
        swap(s[i],s[j]);
        j--;
        i++;
    }
    }
};