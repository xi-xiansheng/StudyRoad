class Solution {
public:

    vector<vector<string>> vvs;

    void Parenthesis(int n)
    {
        if (n == 1)
        {
            vvs[1] = vector<string>{ "()" };
            return;
        }
        Parenthesis(n - 1);
        string s = "(";
        for (int i = 0; i <= n - 1; i++)
        {

            for (const auto e : vvs[i])
            {
                s = "(";
                s += e;
                s += ")";
                for (const auto e : vvs[n - 1 - i])
                {
                    string tmp = s;
                    tmp += e;
                    vvs[n].push_back(tmp);
                }
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return vector<string>();
        vvs.resize(0);
        vvs.resize(n + 1);
        vvs[0] = vector<string>{ "" };
        Parenthesis(n);
        return vvs[n];
    }
};