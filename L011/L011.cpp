/* //第一个为gcm算法，时间复杂度O(n^2)。第二个算法是网上算法，时间复杂度O(n)，非常好！！！)
class Solution {
public:
    int min(int i, int j){
        if (i < j) return i;
        else return j;
    }
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n == 0 || n == 1)
            return 0;
        int max = min(height[0], height[n-1])*(n - 1);
        int high = min(height[0], height[n-1]);
        int con = 0;
        for(int i = 0; i < n; i++) {
            for(int m = n-1; m > i; m--) {
                int nowhigh = min(height[i], height[m]);
                if (nowhigh < high)
                    continue;
                else{
                    con = nowhigh*(m-i);
                    if (con > max){
                        max = con;
                        high = nowhigh;
                    }
                }
            }
        }
        return max;
    }
};
*/
class Solution {
public:
    int maxArea(vector<int> &height) 
    {
        int capability = 0;
        size_t left = 0, right = height.size() - 1;
        
        while (left < right)
        {
            const int water = 
                min(height[left], height[right]) * (right - left);
            
            if (water > capability) capability = water;
            
            if (height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        
        return capability;
    }
};