class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int index = 0;
        int i = 1;
        vector<int> vc;
        vc.resize(n);
        while (index < n && i)
        {
            if (i <= n)
            {
                vc[index++] = i;
            }
            if (i * 10 <= n)
            {
                i *= 10;
                continue;
            }
            if (i % 10 == 9)
            {
                while (i % 10 == 9)
                {
                    i /= 10;
                }
            }
            i++;
        }
        return vc;
    }
};