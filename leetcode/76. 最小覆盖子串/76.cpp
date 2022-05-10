class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        map<char, int> ms;
        for (auto e : t)
            ms[e] += 1;
        int count = t.size();
        int slen = s.size();
        int _left, _right, left, right;
        _left = _right = -1;
        left = right = 0;
        while (right < slen)
        {
            bool flag = false;
            while (right < slen && count)
            {
                if (ms.find(s[right]) == ms.end())
                {
                    right++;
                    continue;
                }
                if (ms[s[right]] > 0)
                    count--;
                ms[s[right]] -= 1;
                right++;
            }
            while (left < right && count == 0)
            {
                if (ms.find(s[left]) != ms.end())
                {
                    if (ms[s[left]] >= 0)
                        count++;
                    ms[s[left]] += 1;
                }
                left++;
                flag = true;
            }
            if ((_right - _left > right - left || _left == -1) && flag)
            {
                _left = left - 1;
                _right = right;
            }
        }
        if (_right == -1)
            return "";
        return string(s.begin() + _left, s.begin() + _right);
    }
};