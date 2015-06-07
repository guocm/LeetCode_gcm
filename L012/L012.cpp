//gcm版本
class Solution {
public:
    string intToRoman(int num) {
        string gewei[]  = {"I", "II", "III", "IV", "V", "VI","VII", "VIII", "IX"};
        string shiwei[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string baiwei[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string qianwei[]  = {"M", "MM", "MMM"};
        string Roman = "";
        int newnum = num;
        int i = 4;
        while(i > 0)
        {
            if (i == 4 &&  newnum /1000 != 0)
            {
                Roman = Roman + qianwei[newnum / 1000 - 1];
                newnum = newnum % 1000;
            }
            else if (i == 3 &&  newnum /100 != 0)
            {
                Roman = Roman + baiwei[newnum / 100 - 1];
                newnum = newnum % 100;
            }
            else if (i == 2 &&  newnum /10 != 0)
            {
                Roman = Roman + shiwei[newnum / 10 - 1];
                newnum = newnum % 10;
            }
            else if (i == 1 &&  newnum  != 0)
            {
                Roman = Roman + gewei[newnum  - 1];
            }
            i--;
        }
        return Roman;
    }
};

//Online, it is very fine!
class Solution {
public:
    string intToRoman(int num) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string numRoman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        string roman = "";
        int newnum = num;
        for (int i = 0; i < 13; i++) {  
            while (newnum >= values[i]) {  
                newnum -= values[i];  
                roman += numRoman[i];  
            }  
        } 
        return roman;
    }
};