class Solution {
public:
    bool checkOnesSegment(string s) {
        int count1 = 0;
        for (int i = 0, sz = s.size(); i < sz; )
        {
            while (i < sz && s[i] == '1')
            {
                i++;
            }
            count1++;
            if (count1 > 1)  return false;
            while (i < sz && s[i] == '0')
            {
                i++;
            }
        }
        return count1 <= 1;
    }
};