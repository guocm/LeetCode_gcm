class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1)
            return len;
        int index = 0;
        for(int i = 1; i < len; ++i){
            if (nums[index] != nums[i]){
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
};

/******
自己的想法：每次判断到有重复的数字，则只保留一个，其后的数字全部向前移。
改进的想法：定义两个下标，一个代表重新赋值后的下标，另一个代表当前指针移动下标，判断到不一样的，向重新赋值后的下标所代表数组赋值。因为重新赋值后的下标总是小于当前指针下标的，所以可行。
心得：可用数组下标定位、操作来取代整个数组的重复操作。
******/