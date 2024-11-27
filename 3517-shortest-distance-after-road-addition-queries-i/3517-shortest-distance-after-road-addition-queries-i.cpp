class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
         vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        graph[i].emplace_back(i + 1, 1); 
    }

    vector<int> result;
    auto dijkstra = [&](int src, int dest) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[src] = 0;
        pq.emplace(0, src);

        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            if (currentDist > dist[u]) continue;

            for (auto& [v, weight] : graph[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist[dest];
    };
    for (auto& query : queries) {
        int u = query[0], v = query[1];
        graph[u].emplace_back(v, 1); 
        int shortestPath = dijkstra(0, n - 1);
        result.push_back(shortestPath);
    }

    return result;
    }
};