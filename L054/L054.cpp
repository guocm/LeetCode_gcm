class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0){
            return res;
        }
        int n = matrix[0].size();
        for (int len = 0, wid = 0; len < n, wid < m; ++len, ++wid, --m, --n){
            for (int j = len; j < n; ++j)
                    res.push_back(matrix[wid][j]);
            for (int i = wid + 1; i < m; ++i){
            	if (n-1 >= len)
                	res.push_back(matrix[i][n-1]);
            }
            for (int j = n - 2; j >= len; --j){
            	if (m - 1 >= wid + 1)
                	res.push_back(matrix[m-1][j]);
            }
            for (int i = m - 2; i > wid; --i){
            	if (len < n - 1)
	                res.push_back(matrix[i][len]);
            }
        }
        return res;
    }
};