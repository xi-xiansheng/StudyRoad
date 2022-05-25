struct Comp {
    bool operator()(string s1, string s2)
    {
        int sz = s1.size() + s2.size();
        string _s1 = s2 + s1;
        string _s2 = s1 + s2;
        int index = 0;
        while (index < sz) {
            if (_s1[index] > _s2[index])
                return true;
            else if (_s1[index] < _s2[index])
                return false;
            else
                index++;
        }
        return false;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int sz = nums.size();
        vector<string> v(sz);
        for (int i = 0; i < sz; i++)
        {
            v[i] = to_string(nums[i]);
        }
        std::sort(v.begin(), v.end(), Comp());
        string s;
        for (int i = sz - 1; i >= 0; i--)
            s += v[i];
        if (nums.size() == 0 || s[0] == '0')
            return "0";
        return s;
    }
};