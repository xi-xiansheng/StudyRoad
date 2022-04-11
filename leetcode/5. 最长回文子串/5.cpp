class Solution {
public:
    string longestPalindrome(string s) {
        int max_left = 0;
        int max_right = 0;
        int index = 0;
        while (index < s.size())
        {
            int left, right;
            left = right = index;
            //以该下标为中心
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }
            if ((right - left - 2) > max_right - max_left)
            {
                max_right = right - 1;
                max_left = left + 1;
            }
            //左右为中心
            left = right = index;
            left--;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }
            if ((right - left - 2) > max_right - max_left)
            {
                max_right = right - 1;
                max_left = left + 1;
            }
            index++;
        }
        return string(s.begin() + max_left, s.begin() + max_right + 1);
    }
};