class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> vi;
        int len = words[0].size();
        unordered_map<string, int> _map;
        for (auto e : words)
        {
            _map[e] += 1;
        }
        int first = -1;
        int last = 0;
        for (int index = 0; index <= (int)s.size() - len * (int)words.size(); index++)
        {
            last = index;
            first = last - 1;
            for (int i = index; i <= ((int)s.size() - len) && (i - index + len) <= len * words.size(); i += len)
            {
                string tmp(s.begin() + i, s.begin() + i + len);
                if (_map.find(tmp) == _map.end())
                {
                    break;
                }
                else if (_map[tmp] == 0)
                {
                    break;
                }
                else
                {
                    _map[tmp] -= 1;
                    first = i;
                }
                if ((first - last + len) == len * words.size())
                {
                    vi.push_back(last);
                    string _tmp(s.begin() + last, s.begin() + last + len);
                    _map[_tmp] += 1;
                    last += len;
                }
            }
            if ((first - last + len) == len * words.size())
            {
                vi.push_back(last);
            }
            _map.clear();
            for (auto e : words)
            {
                _map[e] += 1;
            }
        }
        return vi;
    }
};