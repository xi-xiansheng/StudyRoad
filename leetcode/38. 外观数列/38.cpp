class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        int sz = prev.size();
        string s;
        int index = 0;
        while (index < sz)
        {
            int count = 1;
            while (prev[index] == prev[index + 1])
            {
                count++;
                index++;
            }
            s += count + '0';
            s += prev[index++];
        }
        return s;
    }
};