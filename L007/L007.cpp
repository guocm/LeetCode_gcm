class Solution {
public:
    int reverse(int x) {
        long long newx = x;
        if(x < 0)
            newx = -newx;
        std::string str = std::to_string(newx);
        char zifu;
        int len = str.length();
        for (int i = 0; i < len/2; i++)
        {
            zifu = str[i];
            str[i] = str[len-i-1];
            str[len-i-1] = zifu;
        }
        if (x > 0 && len == 10 && str > "2147483647" || x < 0 && len == 10 && str > "2147483648")
            return 0;
        else
            newx = atoi(str.c_str());
        if (x < 0)
            newx = -newx;
        return newx;
    }
};