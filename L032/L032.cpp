class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> charStack;
        int length = s.length();
        vector<bool> result(length, false);
        for(int i = 0; i < length; ++i){
            switch(s[i]){
                case '(':
                    charStack.push(i);
                    break;
                case ')':
                    if(!charStack.empty()){
                        int index = charStack.top();
                        charStack.pop();
                        result[i] = true;
                        result[index] = true;
                    }
                    break;
            }
        }
        int maxLength = 0;
        int tempLength = 0;
        for(int i = 0; i < length; ++i){
            if(result[i]){
                ++tempLength;
                maxLength = max(maxLength, tempLength);
            }
            else{
                tempLength = 0;
            }
        }
        return maxLength;
    }
};