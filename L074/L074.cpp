class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int wid = matrix.size();
        int len = matrix[0].size();
        for (int i = 0, j = len - 1; (i < wid) && (j >= 0);){
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                ++i;
            else{
                --j;
                wid = i + 1;
            }
        }
        return false;
    }
};