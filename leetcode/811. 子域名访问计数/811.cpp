class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        map<string, int> m;
        for (auto& s : cpdomains)
        {
            int i = 0, sz = s.size();
            while (i < sz && s[i] != ' ')
            {
                i++;
            }
            int count = stoi(string(s.begin(), s.begin() + i));
            while (i < sz)
            {
                i++;
                m[string(s.begin() + i, s.end())] += count;
                while (i < sz && s[i] != '.')
                {
                    i++;
                }
            }
        }
        for (auto& [k, v] : m)
        {
            ans.push_back(to_string(v) + " " + k);
        }
        return ans;
    }
};