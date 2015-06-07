/* //gcm (和下边的思想一样，时间复杂度一样，但写法不同，所用时间较长)
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (numRows == 1 || len <= numRows)
            return s;
        string news = "";
        for (int row = 1; row <= numRows; row++)
        {
            int i = row - 1;
            news = news + s[i];
            if (row == 1 || row == numRows)
            {
                while (1)
                {
                    i = i + 2*(numRows - 1);
                    if (i < len)
                        news = news + s[i];
                    else
                        break;
                }
            }
            else
            {
                while (1)
                {
                    i = i + 2*(numRows - row);
                    if (i < len)
                        news = news + s[i];
                    else
                        break;
                    i = i + 2*(row -1);
                    if (i < len)
                        news = news + s[i];
                    else
                        break;
                }
            }
        }
        return news;
    }
};
*/
// 
class Solution {  
public:  
    string convert(string s, int nRows) {  
        if (nRows <= 1 || s.length() <= nRows)  
           return s;  
        string res = "";  
        int len = s.length();  
        for (int i = 0; i < nRows; ++i) {  
            int indx = i;  
            res += s[indx];  
            int k = 1;
            while (indx < len) {
                if (i == 0 || i == nRows - 1) {  
                    indx += 2 * (nRows - 1);  
                } 
                else {
                    if (k & 0x1)  //奇数位  
                        indx += 2 * (nRows - 1 - i);  
                    else indx += 2 * i;
                }
                if (indx < len) {  
                    res += s[indx];  
                }  
                k++;
            }
        }  
        return res;  
    }  
};  