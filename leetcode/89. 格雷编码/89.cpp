class Solution {
public:
    void GrayCode(vector<int>& vc, int n)
    {
        if (n == 0)
            return;
        GrayCode(vc, n - 1);
        int sz = int(pow(2, n - 1));
        for (int index = 0; index < sz; index++)
        {
            vc[index + sz] = vc[sz - 1 - index];
            vc[index + sz] |= 1 << (n - 1);
        }
    }

    vector<int> grayCode(int n) {
        int sz = int(pow(2, n));
        vector<int> vc(sz, 0);
        GrayCode(vc, n);
        return vc;
    }
};