class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int m = -1;
        for (int i = 0; i < len; ){
            int j = len - 1;
            ++m;
            if (m > 1)
                break;
            while (i < j){
                while ((i < j) && (nums[i] == m)){
                    ++i;
                } 
                while ((j > i) && (nums[j] != m)){
                    --j;
                }
                if (i < j){
                    nums[j] = nums[i];
                    nums[i] = m;
                }
            }
        }
    }
};
/********
 * 有四种方法:
 * 一、直接排序法
 * 二、遍历两遍，第一遍分别统计0、1、2的数目。第二遍根据0、1、2的count,逐个输出。
 * 三、遍历一遍，遇到0，则从前向后放，遇到2，则从后向前放。中间剩下的元素用1填满。
 * 四、从前向后遇到第一个不是0的，从后向前遇到第一个是0的，交换，直到从前向后的下标大于从后向前的下标。
 *     然后从0的后边开始遍历，从前向后遇到第一个不是1的，从后向前遇到第一个不是1的，交换...
 * *******/