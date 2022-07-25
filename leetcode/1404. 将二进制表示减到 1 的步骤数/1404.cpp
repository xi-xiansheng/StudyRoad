class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        int index = s.size() - 1;
        while (index > 0)
        {
            if (s[index] == '0')
            {
                ans++;
                index--;
            }
            else
            {
                ans++;
                while (index >= 0 && s[index] == '1')
                {
                    ans++;
                    index--;
                }
                if (index > 0)
                    s[index] = '1';
            }
        }
        return ans;
    }
};