class Solution {
public:
    bool IsIPV4(string s)
    {
        int sz = s.size();
        int left = 0;
        int right = 0;
        int count = 0;
        for (int i = 0; i < sz; i++)
        {
            while (right < sz && s[right] != '.')
            {
                if (s[right] >= '0' && s[right] <= '9')
                    right++;
                else
                    return false;
            }
            if (right - left < 1 || right - left > 3)
                return false;
            string inter(s.begin() + left, s.begin() + right);
            if (inter.size() == 0 || (inter[0] == '0' && inter.size() > 1))
                return false;
            if (stoi(inter) > 255)
                return false;
            i = right;
            left = ++right;
            count++;
        }
        return count == 4 && (s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9');
    }

    bool LegalChar(char ch)
    {
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))
            return true;
        return false;
    }

    bool IsIPV6(string s)
    {
        int sz = s.size();
        int left = 0;
        int right = 0;
        int count = 0;
        for (int i = 0; i < sz; i++)
        {
            while (right < sz && s[right] != ':')
            {
                if (LegalChar(s[right]))
                    right++;
                else
                    return false;
            }
            if (right - left < 1 || right - left > 4)
                return false;
            string inter(s.begin() + left, s.begin() + right);

            i = right;
            left = ++right;
            count++;
        }
        return count == 8 && LegalChar(s[s.size() - 1]);
    }


    string validIPAddress(string queryIP) {
        if (IsIPV4(queryIP))
            return "IPv4";
        if (IsIPV6(queryIP))
            return "IPv6";
        return "Neither";
    }
};