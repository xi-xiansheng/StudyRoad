class Solution {
public:
    string reverseWords(string s) {

        //std::reverse(s.begin(), s.end());
        string::iterator begin = s.begin();
        string::iterator end = s.begin();
        while (*end != '\0')
        {
            while (*(end + 1) != ' ' && *(end + 1) != '\0')
            {
                end++;
            }
            std::reverse(begin, end + 1);
            end++;
            begin = end + 1;
        }
        return s;
    }
};