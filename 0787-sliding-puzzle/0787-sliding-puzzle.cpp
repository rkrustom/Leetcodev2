class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (const auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }
        string target = "123450";
        vector<vector<int>> moves = {
            {1, 3},       
            {0, 2, 4},   
            {1, 5},       
            {0, 4},      
            {1, 3, 5},    
            {2, 4}        
        };
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({start, 0});
        visited.insert(start);
        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            if (curr == target) return steps;
            int zeroPos = curr.find('0');
            for (int nextPos : moves[zeroPos]) {
                string next = curr;
                swap(next[zeroPos], next[nextPos]);
                if (visited.count(next) == 0) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
        }
        return -1;
    }
};