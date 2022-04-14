class Solution {
public:
    string multiply(string num1, string num2) {
        int carry = 0;
        size_t p1 = 0, p2 = 0;
        string s = "";
        for (size_t i = 0; i < num1.size() + num2.size(); i++)
        {
            s += '0';
        }

        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        while (p1 < num1.size())
        {
            p2 = 0;
            while (p2 < num2.size())
            {
                carry = (num1[p1] - '0') * (num2[p2] - '0');
                s[p1 + p2] += carry % 10;
                carry = carry / 10;
                s[p1 + p2 + 1] += carry;
                p2++;
            }
            for (size_t i = p1; i < num1.size() + num2.size(); i++)
            {
                int flag = (s[i] - '0') / 10;
                s[i] = (s[i] - '0') % 10 + '0';
                s[i + 1] += flag;
            }
            p1++;
        }
    std:reverse(s.begin(), s.end());
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] != '0')
            {
                return string(s.begin() + i, s.end());
            }
        }
        return "0";

    }
};