class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        if(x >= 0 && x < 10)return true;
        int weishu = 0;
        int newx = x;
        int lowx, highx;
        while(newx > 0)
        {
            newx = newx / 10;
            weishu++;
        }
        int num = weishu/2;
        int chushu = pow(10, num);
        lowx = x % chushu;
        highx =  x / chushu;
        if (weishu % 2 == 1)highx =  highx / 10;
        while(highx % 10 == 0)highx = highx / 10;
        int newhigh = 0;
        while(highx > 0)
        {
            newhigh = newhigh*10 + highx % 10;
            highx = highx / 10;
        }
        if(lowx == newhigh)return true;
        else 
            return false;
    }
};