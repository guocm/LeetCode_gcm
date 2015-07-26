class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        int mid = 1;
        for (int i = 0; i < 32; ++i){
            if ((n & mid) > 0)
                sum +=1;
            mid <<= 1;
        }
        return sum;
    }
};