class Solution {
    
    /*
    
    ans = 2 for the following grid
    1   0   0   0
    0   0   0   0
    0   0   2   -1
    
    ans = 4 for the following grid
    1   0   0   0
    0   0   0   0
    0   0   0   2
    */
    
public:
    int nonObstacleCells = 0;
    int DFS(vector<vector<int>>& grid, int cell, int visited) {
        auto r = cell / grid[0].size();
        auto c = cell - (r * grid[0].size());
        
        if(grid[r][c] == 2) {
            if(visited == nonObstacleCells) return 1;   // we found 1 valid path to this destination
            else return 0;  // No valid paths to this destination
        }
        if(grid[r][c] == 3) {
            // already visited
            return 0;   
        }
        if(grid[r][c] == -1 || grid[r][c] == 1) return 0;
        
        // Recursion
        // Mark the cell as visited
        grid[r][c] = 3;
        int ans = 0;
        int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
        for(int i = 0; i < 4; i++) {
            auto x = dx[i] + r;
            auto y = dy[i] + c;
            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
                continue;
            auto nbCell = x * grid[0].size() + y;
            ans += DFS(grid, nbCell, visited + 1);
        }
        // Mark the current cell as available again
        grid[r][c] = 0;
        return ans;    
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int ROWS = grid.size(), COLS = grid[0].size();
        int sx = -1, sy = -1;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == 0) nonObstacleCells++;
                if(grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        
        int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            auto x = dx[i] + sx;
            auto y = dy[i] + sy;
            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
                continue;
            auto nbCell = x * grid[0].size() + y;
            ans += DFS(grid, nbCell, 0);
        }        
        return ans;
    }
};
