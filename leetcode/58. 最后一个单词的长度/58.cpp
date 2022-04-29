class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        auto it = s.rbegin();
        while (it != s.rend())
        {
            while (it != s.rend() && !isalpha(*it))
            {
                it++;
            }
            while (it != s.rend() && isalpha(*it))
            {
                len++;
                it++;
            }
            break;
        }
        return len;
    }
};