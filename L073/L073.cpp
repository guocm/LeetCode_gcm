class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //set 是无序的集合
        unordered_set<int> mwid;
        unordered_set<int> nlen;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if (matrix[i][j] == 0){
                    mwid.insert(i);
                    nlen.insert(j);
                }
            }
        }
        //set的遍历
        for (int h : mwid){
            for (int k = 0; k < n; ++k){
                matrix[h][k] = 0;
            }
        }
        for (int h : nlen){
            for (int k = 0; k < m; ++k){
                matrix[k][h] = 0;
            }
        }
    }
};