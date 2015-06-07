//gcm
class Solution {
public:
    int romanToInt(string s) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string numRoman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        int num = 0;
        string news = s;
        int j = 0;
        for (int i = 0; i < 13; i++) {  
            int len = numRoman[i].length();
            news = s.substr(j, len);
            while (news == numRoman[i]) {  
                num += values[i];
                j += len;
                news = s.substr(j, len);
            }  
        } 
        return num;
    }
};
