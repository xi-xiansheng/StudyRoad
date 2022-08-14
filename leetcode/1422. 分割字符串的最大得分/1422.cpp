class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int left = 0, right = 0;
        for (auto& ch : s) {
            if (ch == '1')
                right++;
        }
        for (int i = 0, sz = s.size(); i < sz - 1; i++) {
            if (s[i] == '0') {
                left++;
            }
            else {
                right--;
            }
            ans = std::max(ans, left + right);
        }
        return ans;
    }
};