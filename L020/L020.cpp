class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> charstack;
        size_t i = 0;
        if (len % 2 == 1)
            return false;
        while( i < len)
        {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[')
            {
                charstack.push(ch);
            }
            else
            {
                if (charstack.size() == 0)
                    return false;
                char top = charstack.top();
                switch(ch)
                {
                    case ')':
                        if (top == '(')
                            charstack.pop();
                        else
                            return false;
                        break;
                    case '}':
                        if (top == '{')
                            charstack.pop();
                        else
                            return false;
                        break;
                    case ']':
                        if (top == '[')
                            charstack.pop();
                        else
                            return false;
                        break;
                }
            }
            ++i;
        }
        if (charstack.size() == 0)
            return true;
        else
            return false;
    }
};