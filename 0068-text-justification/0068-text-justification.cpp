class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int totalChars = words[index].size();
            int last = index + 1;
            while (last < n) {
                if (totalChars + 1 + words[last].size() > maxWidth) break;
                totalChars += 1 + words[last].size();
                last++;
            }

            string line;
            int numWords = last - index;
            if (last == n || numWords == 1) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                while (line.size() < maxWidth) {
                    line += " ";
                }
            } else {
                int spaces = (maxWidth - totalChars) / (numWords - 1);
                int extraSpaces = (maxWidth - totalChars) % (numWords - 1);
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        int spaceCount = spaces + (i - index < extraSpaces ? 1 : 0);
                        for (int j = 0; j <= spaceCount; j++) {
                            line += " ";
                        }
                    }
                }
            }
            result.push_back(line);
            index = last;
        }

        return result;
    }
};