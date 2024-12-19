class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    if(n == 0) return 0;
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    
    int maxChunks = 1; 
    int totalSplits = 1 << (n - 1); 

    for(int mask = 0; mask < totalSplits; ++mask){
       vector<std::vector<int>> chunks;
        vector<int> currentChunk;
        for(int i = 0; i < n; ++i){
            currentChunk.push_back(arr[i]);
            if(i < n -1 && (mask & (1 << i))){
                chunks.push_back(currentChunk);
                currentChunk.clear();
            }
        }
        if(!currentChunk.empty()){
            chunks.push_back(currentChunk);
        }
        vector<int> concatenated;
        for(auto &chunk : chunks){
            vector<int> sortedChunk = chunk;
            sort(sortedChunk.begin(), sortedChunk.end());
            concatenated.insert(concatenated.end(), sortedChunk.begin(), sortedChunk.end());
        }
        if(concatenated == sortedArr){
            maxChunks = std::max(maxChunks, (int)chunks.size());
        }
    }

    return maxChunks;  
    }
};