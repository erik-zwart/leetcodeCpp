class Solution {
    unordered_map<int, int> map;
    int DFS(vector<vector<int>>& grid, int cell) {
        
        if(map.find(cell) != map.end()) return map[cell];
        
        int rows = grid.size(), cols = grid[0].size();
        auto r = cell / cols;
        auto c = cell - r * cols;
        
        if(grid[r][c] == 1) {
            map[cell] = 0;
            return 0;
        }
        
        if(r == rows - 1 && c == cols - 1) return 1;        
        
        int dx[] = {1, 0}, dy[] = {0,1};
        auto ans = 0;
        for(int i = 0; i < 2; i++) {
            auto x = dx[i] + r;
            auto y = dy[i] + c;
            if(x < 0 || x >= rows || y < 0 || y >= cols) continue;
            auto nbCell = x * cols + y;
            ans += DFS(grid, nbCell);
        }
        map[cell] = ans;
        return ans;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
        return DFS(obstacleGrid, 0);
    }
};
