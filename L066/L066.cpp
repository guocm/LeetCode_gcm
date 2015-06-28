class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry = 1;
        for (int i = len - 1; i >= 0; --i){
            int num = digits[i] + carry;
            if (num < 10){
                digits[i] = num;
                carry = 0;
            }else{
                digits[i] = num - 10;
                carry = 1;
            }
        }
        if (carry == 1){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};