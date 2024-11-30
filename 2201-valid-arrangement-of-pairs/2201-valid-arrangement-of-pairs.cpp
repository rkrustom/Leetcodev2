class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
       unordered_map<int, vector<int>> graph;  
    unordered_map<int, int> outDegree, inDegree;
    for (const auto& pair : pairs) {
        int start = pair[0], end = pair[1];
        graph[start].push_back(end);
        outDegree[start]++;
        inDegree[end]++;
    }
    int startNode = pairs[0][0];  
    for (const auto& [node, degree] : outDegree) {
        if (outDegree[node] - inDegree[node] == 1) {
            startNode = node;
            break;
        }
    }
    stack<int> st;
    deque<vector<int>> result;  
    st.push(startNode);

    while (!st.empty()) {
        int node = st.top();
        if (!graph[node].empty()) {
            int nextNode = graph[node].back();
            graph[node].pop_back();
            st.push(nextNode);
        } else {
            st.pop();
            if (!st.empty()) {
                result.push_front({st.top(), node});
            }
        }
    }
    return vector<vector<int>>(result.begin(), result.end());  
    }
};