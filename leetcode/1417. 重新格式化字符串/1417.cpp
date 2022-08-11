class Solution {
public:
    string reformat(string s) {
        int numbercount = 0;
        int fcount = 0;
        for (auto& ch : s)
        {
            if (islower(ch))
                fcount++;
            else
                numbercount++;
        }
        if (abs(fcount - numbercount) > 1)
            return "";
        if (fcount > numbercount)
        {
            for (int i = 0, cur = 1, sz = s.size(); i < sz; i += 2)
            {
                if (isdigit(s[i]))
                {
                    while (cur < sz && isdigit(s[cur])) {
                        cur += 2;
                    }
                    std::swap(s[i], s[cur]);
                }
            }
        }
        else
        {
            for (int i = 0, cur = 1, sz = s.size(); i < sz; i += 2)
            {
                if (islower(s[i]))
                {
                    while (cur < sz && islower(s[cur])) {
                        cur += 2;
                    }
                    std::swap(s[i], s[cur]);
                }
            }
        }
        return s;
    }
};