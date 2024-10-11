class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
    
        vector<pair<int, pair<int, bool>>> events; 
        
        for (int i = 0; i < n; ++i) {
            events.push_back({times[i][0], {i, true}});  
            events.push_back({times[i][1], {i, false}});  
        }
        
 
        for (const auto& event : events) {
            cout << "Time: " << event.first << " FriendIndex: " << event.second.first << " isArrival: " << event.second.second << endl;
        }

  
        sort(events.begin(), events.end(), [](const pair<int, pair<int, bool>>& a, const pair<int, pair<int, bool>>& b) {
            if (a.first == b.first) {
                return a.second.second < b.second.second; // Process leaving before arrival if same time
            }
            return a.first < b.first;
        });
        
  
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i);
        }
        
  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs; // {leaveTime, chairNumber}
        
       
        for (const auto& event : events) {
            int time = event.first;
            int friendIndex = event.second.first;
            bool isArrival = event.second.second;
            
       
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= time) {
                availableChairs.push(occupiedChairs.top().second); // Add the chair back to available
                occupiedChairs.pop();
            }
            
            if (isArrival) {
             
                int chair = availableChairs.top();
                availableChairs.pop();
                
                if (friendIndex == targetFriend) {
                    return chair;
                }
                
                occupiedChairs.push({times[friendIndex][1], chair});
            }
        }
        
        return -1; 
    }
};
