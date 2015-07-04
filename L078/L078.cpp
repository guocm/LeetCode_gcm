class Solution {
public:
     void comb(vector<int>& nums, int index, vector<vector<int>> &res, vector<int> &path){
         int len = nums.size();
         if(path.size() == len - 1){
             return;
         }
         for(int i = index+1; i < len; i++)
         {
             path.push_back(nums[i]);
             comb(nums,i,res,path);
             res.push_back(path);//'index + 1' elements
             path.pop_back();
         }
     }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> res;
        vector<int> mid;
        res.push_back(mid);
        int len = nums.size();
        if(len == 0)
            return res;
        sort(nums.begin(), nums.end());
        vector<int> path;
		for(int i =0; i < len; ++i)
		{
			path.push_back(nums[i]);
			comb(nums,i,res,path);
            res.push_back(path);//1 element
			path.pop_back();
		}
		//whole
		if(len > 1)
	    	res.push_back(nums);
    }
};