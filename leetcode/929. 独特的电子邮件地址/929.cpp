class Solution {
public:
    string EMailDif(const string& s)
    {
        bool flagat = false;
        string ret = "";
        int sz = s.size();
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == '+')
            {
                while (i < sz && s[i] != '@')
                {
                    i++;
                }
                while (i < sz)
                {
                    ret += s[i];
                    i++;
                }
            }
            else if (s[i] == '@')
            {
                flagat = true;
                ret += '@';
            }
            else if (s[i] == '.')
            {
                if (flagat)
                    ret += '.';
            }
            else
                ret += s[i];
        }
        return ret;
    }

    int numUniqueEmails(vector<string>& emails) {
        for (const string& s : emails)
        {
            ans.insert(EMailDif(s));
        }
        return ans.size();
    }
private:
    set<string> ans;
};