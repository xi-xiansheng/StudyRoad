class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1)
        {
            int sz = s.size();
            vector<string> v(sz);
            for (int i = 0; i < sz; i++)
            {
                v[i] = string(s.begin() + i, s.end()) + string(s.begin(), s.begin() + i);
            }
            int index = 0;
            for (int i = 1; i < sz; i++)
            {
                if (v[index].compare(v[i]) > 0)
                    index = i;
            }
            return v[index];
        }
        std::sort(s.begin(), s.end());
        return s;
    }
};