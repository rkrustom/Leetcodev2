class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       auto gain = [](const pair<int, int>& a) {
            double pass = a.first, total = a.second;
            return (pass + 1) / (total + 1) - pass / total;
        };
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& c : classes) {
            int pass = c[0], total = c[1];
            maxHeap.push({gain({pass, total}), {pass, total}});
        }
        while (extraStudents--) {
            auto [currentGain, classData] = maxHeap.top();
            maxHeap.pop();
            int pass = classData.first, total = classData.second;
            pass++;
            total++;
            maxHeap.push({gain({pass, total}), {pass, total}});
        }
        double totalAverage = 0.0;
        while (!maxHeap.empty()) {
            auto [currentGain, classData] = maxHeap.top();
            maxHeap.pop();

            int pass = classData.first, total = classData.second;
            totalAverage += (double)pass / total;
        }
        return totalAverage / classes.size(); 
    }
};