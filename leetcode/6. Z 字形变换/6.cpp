class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        string ss;
        int index = 0;
        int section = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 1; j <= s.size() / +1; j++)
            {
                if (((j - 1) * section + i) < s.size())
                    ss += s[(j - 1) * section + i];
                if ((j * section - i) && i && (j * section - i) != ((j - 1) * section + i) &&
                    (j * section - i) < s.size())
                    ss += s[j * section - i];
            }
        }
        return ss;
    }
};
//Ê±¼ä¸´ÔÓ¶ÈO(N)