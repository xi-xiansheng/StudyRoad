class Solution {
public:
    int _titlenumber(string s, int index, int number)
    {
        int sz = s.size();
        if (index >= sz)
        {
            return number;
        }
        number = number * 26 - 'A' + 1 + s[index];
        return _titlenumber(s, index + 1, number);
    }

    int titleToNumber(string columnTitle) {
        return _titlenumber(columnTitle, 0, 0);
    }
};