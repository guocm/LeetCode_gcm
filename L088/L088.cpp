class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, cur = m + n -1;
        while (i >= 0 && j >= 0){
            if (nums1[i] >= nums2[j]){
                nums1[cur--] = nums1[i--];
            }else{
                nums1[cur--] = nums2[j--];
            }
        }
        while (i >= 0){
            nums1[cur--] = nums1[i--];
        }
        while (j >= 0){
            nums1[cur--] = nums2[j--];
        }
    }
};
/*********
 * 采用的是尾插法,不需要移动数据和额外的空间(此题比较特殊,num1给定了足够的空间)
 * 若不用尾插法,则需要额外的m + n个空间来存储排好序的序列. 
 * ******/