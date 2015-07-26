class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        map <int, int> mapArr;
        for (int i = 0; i < len; ++i){
            if (mapArr.find(nums[i]) == mapArr.end()){
                mapArr.insert(pair<int,int>(nums[i], i));
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