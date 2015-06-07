class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int>> ret;
            int len = num.size();
            if (len <= 2)
                return ret;
            sort (num.begin(), num.end());
            for (int i = 0; i <= len -3; i++){
                int j = i + 1;
                int k = len - 1;
                while (j < k){
                    if (num[i] + num[j] == -num[k]){
                        ret.push_back({num[i], num[j], num[k]});
                        ++j;
                        --k;
                        while(j < k && num[j] == num[j - 1])
                            ++j;
                        while(j < k && num[k] == num[k + 1])
                            --k;
                    }else if (num[i] + num[j] > -num[k]){
                        --k;
                    }else{
                        ++j;
                    }
                }
                while(i <= len-3 && num[i] == num[i + 1]){
                    i++;
                }
            }
            return ret;
        }
};
