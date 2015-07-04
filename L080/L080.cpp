class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return len;
        int i = 0, j = 1, k = 0;
        while(j < len){
            if (nums[i] == nums[j]){
                ++k;
                if(k == 1){
                    nums[++i] = nums[j++];
                }
                else if(k > 1){
                   ++j; 
                }
            }else{
                nums[++i] = nums[j++];
                k = 0;
            }
        }
        return i+1;
    }
};