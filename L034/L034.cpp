class Solution {
private:
    int getMid(int start, int end){
        long long llStart = (long long)start;
        long long llEnd = (long long)end;
        return int((llStart + llEnd)/2);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int start = 0;
        int end = len - 1;
        vector<int> res;
        while(start <= end){
            int mid = getMid(start, end);
            if(nums[mid] == target){
                int startindex = mid;
                int endindex = mid;
                while(startindex >= 0 && nums[--startindex] == target){}
                ++startindex;
                while(endindex <= end && nums[++endindex] == target){}
                --endindex;
                res.push_back(startindex);
                res.push_back(endindex);
                return res;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};