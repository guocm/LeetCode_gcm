class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        map <int, int> mapArr;
        for (int i = 0; i < len; ++i){
            if (mapArr.find(nums[i]) == mapArr.end()){
                mapArr[nums[i]] = 1;
            }else{
                return true;
            }
        }
        return false;
    }
};