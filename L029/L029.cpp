class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return -1;
        long long res = 0;
        long long flag = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            flag = -1;
        long long divid = abs((long long) dividend);
        long long divi = abs((long long) divisor);
        long long temp = 0;
        while(divi <= divid){
            temp = divi;
            long long cnt = 1;
            while((temp<<= 1) <= divid){
                cnt<<= 1;
            }
            res += cnt;
            divid -= (temp>>= 1);
        }
        if (res*flag > 2147483647 || res*flag < -2147483648 ){
            return 2147483647;
        }
        else
        return (int)res*flag;
    }
};