class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        string res = "";
        int carry = 0;
        int i = 0, j = 0; 
        //两个条件同时判断,中间要用&&或者||,而不能直接用","隔开.
        for (i = len1 -1, j = len2 -1; i >= 0 || j >=0; --i, --j){
            int val = 0;
            if (i >=0 && j >= 0)
                val = int(a[i]-'0') + int(b[j]-'0') + carry;
            else if (i >=0 && j <= -1)
                val = int(a[i]-'0') + carry;
            else if (i <= -1 && j >=0)
                val = int(b[j]-'0') + carry;
            if ( val > 1){
                res.insert(0, 1, char(val - 2 + 48));
                carry = 1;
            }else{
                res.insert(0, 1, char(val + 48));
                carry = 0;
            }
        }
        if (j <= -1 && i <= -1){
            if (carry == 1)
                res.insert(0, 1, char(carry + 48));
        }
       return res; 
    }
};