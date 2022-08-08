class Solution {
public:
    string makeLargestSpecial(string s) {
        int sz = s.size();
        if (sz <= 2)
            return s;
        vector<string> v;
        int count = 0, cur = 0, prev = 0;
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == '0')
                count--;
            else
                count++;
            if (count == 0)
            {
                string ret = makeLargestSpecial(string(s.begin() + prev + 1, s.begin() + i));
                prev = i + 1;
                ret = "1" + ret + "0";
                v.emplace_back(ret);
            }
        }
        std::sort(v.begin(), v.end(), greater());
        string ans;
        for (auto& ss : v)
        {
            ans += ss;
        }
        return ans;
    }
};