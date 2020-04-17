class Solution {
    int maxSemLen = 0;
    // K = Node, V = in degree
    unordered_map<int, int> inMap;
    
    // Adjacency list
    unordered_map<int, set<int>> aList;
    
    // Memoization: K = Node, V = Max Sem Len
    unordered_map<int, int> memo;
    
    int DFS(int node, unordered_set<int>& visited) {
        if(visited.find(node) != visited.end()) return -1;
        
        if(memo.find(node) != memo.end()) return memo[node];        

        if(aList[node].size() == 0) {
            memo[node] = 1;
            return 1;
        }
        
        int ans = 0;
        int maxAns = 0;
        
        // choose node 
        visited.insert(node);
        
        for(auto nb : aList[node]) {
            ans = DFS(nb, visited);
            if(ans == -1) return -1;
            maxAns = std::max(maxAns, ans);
        }
        
        // unchoose node
        visited.erase(node);
        memo[node] = 1 + maxAns;
        return 1 + maxAns;
    }
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        if(relations.empty()) return 0;
        
        for(int i = 0; i < relations.size(); i++) {
            auto s = relations[i][0];
            auto d = relations[i][1];
            inMap[d]++;
            if(inMap.find(s) == inMap.end()) inMap[s] = 0;
            
            aList[s].insert(d);
            if(aList.find(d) == aList.end()) aList[d].insert({});
        }
        
        auto cycle = true;
        for(auto it = inMap.begin(); it != inMap.end(); it++) {
            if(it->second == 0) {
                cycle = false;
                auto start = it->first;
                
                unordered_set<int> visited;
                visited.clear();
                auto len = DFS(start, visited);
                if(len == -1) return -1;
                maxSemLen = std::max(maxSemLen, len);
                
            }
        }
        if(cycle) return -1;
        return maxSemLen;
    }
};
