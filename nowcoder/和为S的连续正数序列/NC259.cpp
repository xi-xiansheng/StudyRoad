class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > bf;
        int low = 1;
        int heigh;
        int _sum = low + heigh;
        while (low < sum / 2 + 1)
        {
            heigh = low + 1;
            _sum = low + heigh;
            while (_sum < sum)
            {
                heigh += 1;
                _sum += heigh;
            }
            if (_sum == sum)
            {
                int size = bf.size() + 1;
                bf.resize(size);
                bf[size - 1].resize(heigh - low + 1);
                for (int i = 0; i <= heigh - low + 1; i++)
                {
                    bf[size - 1][i] = i + low;
                }
            }
            low++;
        }
        return bf;
    }
};