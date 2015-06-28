class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum = nums[0], maxsum = nums[0];
        for (int i = 1; i < len; ++i){
            if (sum < 0) 
                sum = 0;
            sum += nums[i];
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};