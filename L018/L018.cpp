class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> ret;
            int len = nums.size();
            if (len <= 3)
                return ret;
            sort(nums.begin(), nums.end());
            for (int i = 0; i <= len- 4; ++i) {
                for (int j = i + 1; j <= len - 3; ++j){
                    int k = j + 1;
                    int h = len - 1;
                    while (k < h){
                        if (nums[i] + nums[j] + nums[k] + nums[h] > target){
                            --h;
                        } else if (nums[i] + nums[j] + nums[k] + nums[h] < target){
                            ++k;
                        } else{
                            ret.push_back({nums[i], nums[j], nums[k], nums[h]});
                            ++k;
                            --h;
                            while(nums[k] == nums[k - 1]){
                                ++k;
                            }
                            while(nums[h] == nums[h + 1]){
                                --h;
                            }
                        }
                    }
                    while(j <= len - 3 && nums[j] == nums[j + 1])
                        ++j;
                }
               while(i <= len -4 && nums[i] == nums[i + 1])
                    ++i; 
            }
            return ret;
        }
};
