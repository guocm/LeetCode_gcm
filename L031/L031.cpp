class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() < 2) return;
        int i, k;
        for (i = num.size() - 2; i >= 0; --i)
        {
            if (num[i] < num[i+1])
                break;
        } 
        for (k = num.size() - 1; k > i; --k)
        {
            if (num[i] < num[k])
                break;
        }
        if (i >= 0)
            swap(num[i], num[k]);
        reverse(num.begin() + i + 1, num.end());
    }
};
/*********
例：设有排列(p)=2763541,按照字典式排序,它的下一个排列是(q)=2764135
(1)2763541[找最后一个正序35]
(2)2763541[找3后面比3大的最后一个数]
(3)2764531[交换3,4的位置]
(4)2764135[把4后面的531反序排列为135即得到最后的排列(q)]
**********/