class Solution {
    void sortDiagonal(vector<vector<int>>& matrix, int sr, int sc) {
        vector<int> arr;
        
        auto r = sr;
        auto c = sc;
        while(r < matrix.size() && c < matrix[0].size()) {
            arr.push_back(matrix[r][c]);
            r++; c++;
        }
        std::sort(arr.begin(), arr.end());
        r = sr;
        c = sc;
        int i = 0;
        while(r < matrix.size() && c < matrix[0].size()) {
            matrix[r][c] = arr[i++];
            r++; c++;
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(mat.empty()) return mat;
        
        for(int r = 0; r < mat.size(); r++) 
            sortDiagonal(mat, r, 0);
        for(int c = 0; c < mat[0].size(); c++)
            sortDiagonal(mat, 0, c);
        return mat;
    }
};
