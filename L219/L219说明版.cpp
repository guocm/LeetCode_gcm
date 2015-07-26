class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len <= 1)
            return false;
        unordered_map <int, int> mapArr; //不用排序的时候用unordered_map，会比map快很多。
        for (int i = 0; i < len; ++i){
            if (mapArr.find(nums[i]) == mapArr.end()){
                //mapArr.insert(pair<int,int>(nums[i], i));
                mapArr[nums[i]] = i;
            }else{
                int res = i - mapArr[nums[i]];
                if (res <= k){
                    return true;
                }else{
                    mapArr[nums[i]] = i;
                }
            }
        }
        return false;
    }
};