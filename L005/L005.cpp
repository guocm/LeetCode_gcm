class Solution {
public:
    string longestPalindrome(string s) {
        unsigned long long s_len = s.length();
        if (s_len == 1)
            return s;
        string str = "";
        unsigned long long str_len = 0;
        for (int i = s_len/2 - 1; i >= 0; i--)
        {
            if (str_len >= 2*(i+1))
                break;
            int subpal_len = 0;
            string subpal = "";
            for(int j = 0; j <= i; j++)
            {
                if (s[i-j] == s[i+j])
                {
                    if(j ==0)
                        subpal_len++;
                    else
                        subpal_len += 2;
                    subpal = s.substr(i-j, subpal_len);
                }
                else
                    break;
            }
            if (subpal_len > str_len)
            {
                str_len = subpal_len;
                str = subpal;
            }
            subpal_len = 0;
            subpal = "";
            for(int j = 0; j <= i; j++)
            {
                if (s[i-j] == s[i+1+j])
                {
                    subpal_len+=2;
                    subpal = s.substr(i-j, subpal_len);
                }
                else
                    break;
            }
            if (subpal_len > str_len)
            {
                str_len = subpal_len;
                str = subpal;
            }
        }
        for (int i = s_len/2; i < s_len; i++)
        {
            if (str_len >= 2*(s_len - i)-1)
                break;
            int subpal_len = 0;
            string subpal = "";
            for(int j = 0; j < s_len-i; j++)
            {
                if (s[i-j] == s[i+j])
                {
                    if (j == 0)
                        subpal_len++;
                    else
                        subpal_len += 2;
                    subpal = s.substr(i-j, subpal_len);
                }
                else
                    break;
            }
            if (subpal_len > str_len)
            {
                str_len = subpal_len;
                str = subpal;
            }
            subpal_len = 0;
            subpal = "";
            for(int j = 0; j < s_len-i; j++)
            {
                if (s[i-j] == s[i+1+j])
                {
                    subpal_len+=2;
                    subpal = s.substr(i-j, subpal_len);
                }
                else
                    break;
            }
            if (subpal_len > str_len)
            {
                str_len = subpal_len;
                str = subpal;
            }
        }
        return str;
    }
};