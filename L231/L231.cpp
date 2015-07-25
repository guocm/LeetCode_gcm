class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i = 1;
        for (int j = 0; j < 31; ++j){
            //if ((n^i) == 0){//判等优先级比抑或优先级高，所以抑或要加括号。
            if (n == i){
                return true;
            }
            i <<= 1;
        }
        return false;
    }
};