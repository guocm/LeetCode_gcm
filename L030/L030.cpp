class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L)
    {
        map<string, int> words, cur;
        vector<int> res;
        int lenL = L.size();
        int lenL0 = L[0].size();
        for(int i = 0; i < lenL; i++)
        {
            words[L[i]]++;
        }
        for(int j = 0; j <= (int)(S.length() - lenL*lenL0); j++)
        {
            cur.clear();
            int k;
            for(k = 0; k < lenL; k++)
            {
                string word = S.substr(j + k*lenL0, lenL0);
                if(words.find(word) == words.end())
                    break;
                cur[word]++;
                if(cur[word] > words[word])
                    break;
            }
            if(k == lenL)
            {
                res.push_back(j);
            }
        }
        return res;
    }
};