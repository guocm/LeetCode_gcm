class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int num = 0;
        int start = 0;
        bool sign = true;
        while(str[start] == ' ')start++;
        if (str == "" || str[start] == '\0')return 0;
        if (str[start] == '-')
        {
            sign = false;
            if (str[start+1] < 48 || str[start+1] > 57)return 0;
            start++;
        }
        else if (str[start] == '+')
        {
            if (str[start + 1] < 48 || str[start + 1] > 57)return 0;
            start++;
        }
        else if (str[start] < 48 || str[start] > 57)return 0;
        long long midNum = 0;
        for (int i = start; i < len; i++)
        {
            if(str[i] < 48 || str[i] > 57 ||midNum > 2147483648)
                break;
            else
                midNum = midNum*10 + (str[i] - 48);
        }
        if (midNum > 2147483647 && sign)
        {
            num = 2147483647;
        }
        else if (midNum > 2147483648 && !sign)num = -2147483648;
	    else
	    {
	        num = int(midNum);
            if (sign == false)num = -num;
	    }
        return num;
    }
};