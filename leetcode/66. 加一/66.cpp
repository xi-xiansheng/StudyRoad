class Solution {
public:
    /*vector<int> plusOne(vector<int>& digits) {
        string s;
        for(const auto e : digits)
            s += '0' + e;
        int CarryBit = 0;
        int sz = digits.size();
        int index = sz - 1;
        CarryBit = (s[index] - '0' + 1) / 10;
        s[index] = (s[index] - '0' + 1) % 10 + '0';
        index--;
        while(index >= 0 && CarryBit)
        {
            CarryBit = (s[index] - '0' + CarryBit) / 10;
            s[index] = (s[index] - '0' + 1) % 10 + '0';
            index--;
        }
        vector<int> vc;
        if(CarryBit)
            vc.push_back(1);
        for(auto e : s)
        {
            vc.push_back(e - '0');
        }
        return vc;
    }*/
    vector<int> plusOne(vector<int>& digits) {
        vector<int> vc;
        int CarryBit = 1;
        int index = digits.size() - 1;
        while (index >= 0 && CarryBit)
        {
            digits[index] += CarryBit;
            CarryBit = digits[index] / 10;
            digits[index] %= 10;
            index--;
        }
        if (CarryBit)
        {
            int sz = digits.size();
            vector<int> vc(sz + 1);
            vc[0] = 1;
            for (int i = 0; i < sz; i++)
                vc[i + 1] = digits[i];
            return vc;
        }
        return digits;
    }
};