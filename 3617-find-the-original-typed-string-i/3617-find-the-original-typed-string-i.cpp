class Solution {
public:
    int possibleStringCount(string word) {
      int n = word.size();
      int total = 1; 
      int i = 0;

        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) {
                j++;
            }
            int len = j - i;
            if (len > 1) {
                total += (len - 1);
            }
            i = j;
        }
        return total;   
    }
};