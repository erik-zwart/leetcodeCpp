class Solution {    
    
    int DFS(int cell, vector<vector<int>>& grid) {
        // Return the max amount of gold that can be collected from the current cell ID         
        auto ROWS = grid.size();
        auto COLS = grid[0].size();
        auto r = cell / COLS;
        auto c = cell - r * COLS;
        
        if(grid[r][c] == 0) return 0;
        
        // collect the gold from the current cell
        auto gold = grid[r][c];
        // Consume the gold at the current cell (as good as marking the cells as visited)
        grid[r][c] = 0; 
        
        int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
        
        auto ans = -1;
        for(int i = 0; i < 4; i++) {
            auto x = dx[i] + r;
            auto y = dy[i] + c;
            if(x < 0 || x >= ROWS || y < 0 || y >= COLS) continue;
            
            auto nbCell = x * COLS + y;
            auto a = DFS(nbCell, grid);            
            ans = std::max(ans, a);            
        }
        
        // Backtrack(Unchoose)
        // Put the original gold back at the current cell 
        // (as good as removing from the visited set)
        grid[r][c] = gold;  
        
        // total gold collected = gold + ans
        return gold + ans;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        
        auto ROWS = grid.size();
        auto COLS = grid[0].size();
        
        auto ans = 0;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                unordered_set<int> visited;
                visited.clear();
                auto cell = i * COLS + j;
                ans = std::max(ans, DFS(cell, grid));
            }
        }
        return ans;
    }
};
