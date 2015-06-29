class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int i = len - 1;
        while((i >= 0) && (s[i] == ' ')){
            --i;
        }
        if (i == -1)
            return 0;
        int j = i;
        while ((j >= 0) && (s[j] != ' ')){
            --j;
        }
        return  i - j;
    }
};
/******
 * while 循环 或者 if等条件语句判断的时候, 最好不要将++i或者--i这样自增自减的语句放在判断条件中。
 * 否则,只是进行判断,就算条件不满足,不执行函数体,i的值也会发生变化,从而影响后续i的值。
 * 因此++i、--i最好放在函数体中执行。
 ******/