class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int closetar = nums[0] + nums[1] + nums[len - 1];
        int sum;
        for(int i = 0; i < len - 2; i++){
            int j = i + 1;
            int k = len - 1;
            while(j < k && closetar != target){
                sum = nums[i] + nums[j] + nums[k];
                if (sum < target){
                    ++j;
                }
                else if (sum > target){
                    --k;
                }
                else{
                    return target;
                }
                if (abs(closetar - target) > abs(sum - target) ){
                    closetar = sum;
                }
            }
        }
        return closetar;
    }
};