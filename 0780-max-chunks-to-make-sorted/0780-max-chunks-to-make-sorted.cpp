class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    int max_so_far = -1;
    int chunks = 0;   
    for(int i = 0; i < arr.size(); ++i){
        max_so_far = std::max(max_so_far, arr[i]);
        if(max_so_far == i){
        chunks++;
        }
    }   
    return chunks;  
    }
};