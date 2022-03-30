class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0;
        int cur = 0;
        int len = 0;
        unordered_map<char, int> unmap;
        while (cur < s.size())
        {
            unmap[s[cur]] += 1;
            if (unmap[s[cur]] > 1)
            {
                if (len < cur - index)
                {
                    len = cur - index;
                }
                while (unmap[s[cur]] > 1)
                {
                    unmap[s[index]] -= 1;
                    index++;
                }
            }
            cur++;
        }
        if (len < cur - index)
        {
            len = cur - index;
        }
        return len;
    }
};