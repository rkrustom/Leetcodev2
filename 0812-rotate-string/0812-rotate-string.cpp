class Solution {
public:
    bool rotateString(string s, string goal) {
       if (s.length() != goal.length()) {
        return false;
    }
    std::string doubled_s = s + s;
    return doubled_s.find(goal) != std::string::npos;  
    }
};