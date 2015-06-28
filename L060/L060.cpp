class Solution {
public:
    string getPermutation(int n, int k) {
        string target = "";
        int factorial = 1;
        for (int j = 0; j < n; j++){
            target += j +'1';
            factorial *= (j + 1);
        }
        int remainder = k - 1;
        int result = 0;
        for (int j = 0; j < n; j++){
            factorial = factorial / (n - j);
            result = remainder / factorial;
            remainder = remainder % factorial;
            if (result != 0){
                target = target.substr(0, j) + target[j + result] + target.substr(j, result) + target.substr(j + result + 1, n-j-result -1);
            }
            if (remainder == 0){
                break;
            }
        }
        return target;
    }
};