class Solution {
    vector<int> getCharMap(string const& s, vector<int>& iter) {
        vector<int> ans(26);
        for(auto c : s) ans[c - 97]++;
        for(int i = 0; i < 26; i++) {
            ans[i] = std::min(ans[i], iter[i]);
        }
        return ans;
    }
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        vector<int> iter(26);
        if(A.empty()) return res;
        
        for(auto c : A[0]) iter[c - 'a']++;
        
        for(int i = 1; i < A.size(); i++) {
            iter = getCharMap(A[i], iter);
        }
        for(int i = 0; i < 26; i++) {
            if(iter[i] > 0) {
                char c = 'a' + i;
                for(int j = 0; j < iter[i]; j++) {
                    string temp = "";
                    temp += c;
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
