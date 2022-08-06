class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int sz = words.size();
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (words[j].find(words[i]) != std::string::npos && i != j)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};