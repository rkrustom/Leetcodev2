class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0)); 
    for (auto& wall : walls) {
        grid[wall[0]][wall[1]] = 1;
    }
    for (auto& guard : guards) {
        grid[guard[0]][guard[1]] = 2;
    }
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto& guard : guards) {
        int x = guard[0], y = guard[1];
        for (auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (grid[nx][ny] == 1 || grid[nx][ny] == 2) 
                    break;
                if (grid[nx][ny] == 0) 
                    grid[nx][ny] = 3;
                nx += dir.first;
                ny += dir.second;
            }
        }
    }
    int unguardedCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) { 
                unguardedCount++;
            }
        }
    }

    return unguardedCount;
    }
};