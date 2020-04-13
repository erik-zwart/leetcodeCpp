class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map;
        for(auto c : s) map[c]++;
        for(auto c : t) {
            if(map.find(c) == map.end()) return c;
            else {
                map[c]--;
                if(map[c] == 0) map.erase(c);
            }
        }
        return '\0';
    }
};
