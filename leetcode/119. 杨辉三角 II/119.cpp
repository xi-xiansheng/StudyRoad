class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex + 1, 1);
        if (rowIndex < 2)
            return v;
        vector<int> prev(v);
        for (int i = 2; i <= rowIndex; i++)
        {
            for (int j = 0; j < i - 1; j++)
            {
                v[j + 1] = prev[j] + prev[j + 1];
            }
            prev = v;
        }
        return v;
    }
};