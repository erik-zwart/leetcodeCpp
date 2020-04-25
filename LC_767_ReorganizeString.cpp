class Solution {
    char getNextChar(map<int, vector<char>, std::greater<int>>& map, char prevChar) {
        // return the highest freq char != prevChar
        if(map.empty()) return '\0';
        
        auto mapIt = map.begin();
        auto res = '\0';
        while(mapIt != map.end()) {
            auto key = mapIt->first;
            auto& vec = mapIt->second;
            for(auto vecIt = vec.begin(); vecIt != vec.end(); vecIt++) {
                if(*vecIt != prevChar) {
                    res = *vecIt;
                    // erase res from the vec
                    vec.erase(vecIt);
                    if(vec.empty()) map.erase(key);
                    // add a new entry in map
                    if(key - 1 > 0) {
                        map[key - 1].push_back(res);
                    }
                    return res;
                }
            }
            mapIt++;
        }
        // Coming here means error
        return res;
    }
    
public:
    string reorganizeString(string S) {
        unordered_map<char, int> freqMap;
        for(const auto& c : S) freqMap[c]++;
        string res(S.length(), '0');
        map<int, vector<char>, std::greater<int>> map;
        for(auto it = freqMap.begin(); it != freqMap.end(); it++) {
            auto k = it->first;
            auto v = it->second;
            map[v].push_back(k);
        }

        int i = 0;
        auto prevChar = '\0';
        while(true) {
            auto nextChar = getNextChar(map, prevChar);
            if(nextChar == '\0') break;
            res[i++] = nextChar;
            prevChar = nextChar;
        }
        if(i != S.length()) return "";
        return res;
    }
};
