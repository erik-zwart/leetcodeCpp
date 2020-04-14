class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        // Key = student ID, V = a priority queue of top 5 marks of the student
        std::map<int, std::priority_queue<int, std::vector<int>, greater<int>>> map;
        
        for(const auto& it : items) {
            auto id = it[0];
            auto marks = it[1];
            
            if(map.find(id) == map.end()) {
                std::priority_queue<int, vector<int>, greater<int>> pq;
                pq.push(marks);
                map[id] = pq;
            } else {
                auto& pq = map[id];
                if(pq.size() == 5) {
                    if(pq.top() < marks) {
                        pq.pop();
                        pq.push(marks);
                    } else {
                        // Do nothing
                    }
                } else {
                    pq.push(marks);
                }
            }
        } // for
        
        vector<vector<int>> ans;
        
        for(auto it = map.begin(); it != map.end(); it++) {
            auto id = it->first;
            auto pq = it->second;
            auto sum = 0;
            while(!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
            ans.push_back({id, sum / 5});
        }
        return ans;
    }
};
