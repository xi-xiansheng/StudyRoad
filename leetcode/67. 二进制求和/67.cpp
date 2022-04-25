class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size())
        {
            std::swap(a, b);
        }
        int carry_bit = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 && j >= 0)
        {
            int tmp = carry_bit;
            carry_bit = (a[i] - '0' + b[j] - '0' + carry_bit) / 2;
            b[j] = (a[i] - '0' + b[j] - '0' + tmp) % 2 + '0';
            i--;
            j--;
        }
        while (j >= 0)
        {
            int tmp = carry_bit;
            carry_bit = (b[j] - '0' + carry_bit) / 2;
            b[j] = (b[j] + tmp - '0') % 2 + '0';
            j--;
        }
        if (carry_bit)
            return "1" + b;
        return b;
    }
};