class Solution {
public:
    int minSteps(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        deque<pair<pair<int,int>, int>> dq;  // ((x, y), steps)
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        dq.push_front({{0, 0}, 0});

        while (!dq.empty()) {
            auto [cell, steps] = dq.front(); dq.pop_front();
            int x = cell.first, y = cell.second;

            if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y])
                continue;

            visited[x][y] = true;

            if (x == n - 1 && y == m - 1)
                return steps;

            for (auto [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
                    if (grid[nx][ny] == 1)
                        dq.push_front({{nx, ny}, steps});      // 0-cost
                    else
                        dq.push_back({{nx, ny}, steps + 1});  // 1-cost
                }
            }
        }

        return -1;  // if not reachable
    }
};
