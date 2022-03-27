class Solution {
public:
    //归并，先排序后统计
    void MergeCount(vector<int>& data, int left, int right, int& num)
    {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        MergeCount(data, left, mid, num);
        MergeCount(data, mid + 1, right, num);
        int indexL = mid;
        int indexR = right;
        vector<int> tmp;
        tmp.resize(right - left + 1);
        int indexT = right - left;
        while (indexL >= left && indexR >= mid + 1)
        {
            if (data[indexL] > data[indexR])
            {
                tmp[indexT--] = data[indexL--];
                num += indexR - mid;
                num %= 1000000007;
            }
            else
            {
                tmp[indexT--] = data[indexR--];
            }
        }
        while (indexL >= left)
        {
            tmp[indexT--] = data[indexL--];
        }
        while (indexR >= mid + 1)
        {
            tmp[indexT--] = data[indexR--];
        }
        indexL = left;
        while (indexL <= right)
        {
            data[indexL++] = tmp[indexL - left];
        }
    }

    int InversePairs(vector<int> data) {
        int num = 0;
        MergeCount(data, 0, data.size() - 1, num);
        return num;
    }
};