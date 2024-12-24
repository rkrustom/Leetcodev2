class Solution {
public:
   pair<int, int> calculateDiameterAndRadius(int n, const vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto bfs = [&](int start) -> pair<int, int> {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        int farthest_node = start;
        int max_dist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);

                    if (dist[neighbor] > max_dist) {
                        max_dist = dist[neighbor];
                        farthest_node = neighbor;
                    }
                }
            }
        }
        return {farthest_node, max_dist};
    };
    pair<int, int> first_bfs = bfs(0);
    int farthest1 = first_bfs.first;
    pair<int, int> second_bfs = bfs(farthest1);
    int diameter = second_bfs.second;
    int radius = (diameter + 1) / 2;
    return {diameter, radius};
}

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int n1 = edges1.size() + 1;
    int n2 = edges2.size() + 1; 
    pair<int, int> tree1 = calculateDiameterAndRadius(n1, edges1);
    pair<int, int> tree2 = calculateDiameterAndRadius(n2, edges2);

    int d1 = tree1.first;
    int r1 = tree1.second;
    int d2 = tree2.first;
    int r2 = tree2.second;
    return max({d1, d2, r1 + r2 + 1});  
    }
};