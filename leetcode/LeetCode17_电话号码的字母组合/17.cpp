class Solution {
public:
    vector<string> vs0 = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    //递归思想
    vector<string> combine(vector<string> vs, string::iterator it)
    {
        if (*it == '\0')
            return vs;
        size_t pointer = *it - '2';
        if (vs.size())
        {
            //循环vs0[pointer].size()次
            vs.resize(vs.size() * vs0[pointer].size());
            for (size_t i = 0; i < vs0[pointer].size(); i++)
            {
                //每次复制原size()次
                for (size_t j = 0; j < vs.size() / vs0[pointer].size(); j++)
                {
                    vs[j + (i + 1) * vs.size() / vs0[pointer].size()] = vs[j];
                }
            }
        }
        else
        {
            vs.resize(vs0[pointer].size());
        }
        for (size_t i = 0; i < vs0[pointer].size(); i++)
        {
            for (size_t j = 0; j < vs.size() / vs0[pointer].size(); j++)
            {
                vs[j + (i)*vs.size() / vs0[pointer].size()] += vs0[pointer][i];
            }
        }
        vs = combine(vs, ++it);
        return vs;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> vs;
        vs.reserve(0);
        vs = combine(vs, digits.begin());
        return vs;
    }
};