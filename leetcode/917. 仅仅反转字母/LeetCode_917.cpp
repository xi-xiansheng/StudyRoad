class Solution {
public:
    string reverseOnlyLetters(string s) {
        string::iterator first = s.begin();
        string::iterator last = s.end() - 1;
        while (first <= last)
        {
            if (!((*first >= 'a' && *first <= 'z') || (*first >= 'A' && *first <= 'Z')))
            {
                first++;
                continue;
            }
            if (!((*last <= 'z' && *last >= 'a') || (*last <= 'Z' && *last >= 'A')))
            {
                last--;
                continue;
            }
            char tmp = *first;
            *first = *last;
            *last = tmp;
            first++;
            last--;
        }
        return s;
    }
};