class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        // write code here
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