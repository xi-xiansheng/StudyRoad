class Solution {
public:
    string defangIPaddr(string address) {
        int sz = address.size();
        address.resize(sz + 6);
        int p = sz;
        for (int i = 3; i > 0; i--)
        {
            while (address[p] != '.')
            {
                address[p + 2 * i] = address[p];
                p--;
            }
            address[p + 2 * i] = ']';
            address[p + 2 * i - 1] = '.';
            address[p + 2 * i - 2] = '[';
            p--;
        }
        return address;
    }
};