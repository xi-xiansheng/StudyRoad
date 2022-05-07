class Solution {
public:
    void ComBine(int index, int n, int k)
    {
        if (k <= 0)
        {
            composition.push_back(_cmb);
            return;
        }
        _suffix++;
        for (int i = index; i < n - k + 1; i++)
        {
            _cmb[_suffix - 1] = i + 1;
            ComBine(i + 1, n, k - 1);
        }
        _suffix--;
    }

    vector<vector<int>> combine(int n, int k) {
        if (k > n)
            return composition;
        _cmb.resize(k);
        _suffix = 0;
        ComBine(0, n, k);
        return composition;
    }
private:
    vector<vector<int>> composition;
    vector<int> _cmb;
    int _suffix;
};