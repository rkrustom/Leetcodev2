class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
         vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                if (champion != -1) {
                    return -1; 
                }
                champion = i;
                q.push(i);
            }
        }
        int visitedNodes = 0;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            visitedNodes++;

            for (int neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return visitedNodes == n ? champion : -1; 
    }
};