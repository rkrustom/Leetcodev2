class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
      int freq[26] = {0};
    for(char c : s) {
        freq[c - 'a']++;
    }
    
    priority_queue<pair<char, int>, vector<pair<char, int>>, function<bool(pair<char, int>, pair<char, int>)>> pq(
        [](pair<char, int> a, pair<char, int> b) -> bool {
            return a.first < b.first; 
        }
    );
    for(int i = 25; i >=0; i--) {
        if(freq[i] > 0) {
            pq.push({char('a' + i), freq[i]});
        }
    }
    
    string result = "";
    
    while(!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        
        char current_char = current.first;
        int current_count = current.second;
        int append_times = min(current_count, repeatLimit);
        result += string(append_times, current_char);
        current_count -= append_times;
        if(current_count > 0) {
            if(pq.empty()) {
                break;
            }
            auto next = pq.top();
            pq.pop();
            
            char next_char = next.first;
            int next_count = next.second;
            result += next_char;
            next_count -= 1;
            pq.push({current_char, current_count});
            if(next_count > 0) {
                pq.push({next_char, next_count});
            }
        }
    }
    
    return result;  
    }
};