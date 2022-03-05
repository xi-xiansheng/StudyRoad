class Solution {
public:
    //Ë¼Â·£º¶ş²æËÑË÷Ê÷
    multiset<int> mst;

    void Insert(int num) {
        mst.insert(num);
    }
    double GetMedian()
    {
        std::multiset<int>::iterator it = mst.begin();
        int i = 0;
        while (i < mst.size() / 2 + mst.size() % 2)
        {
            it++;
            i++;
        }
        double result = double(*--it);
        if (mst.size() % 2 == 0)
        {
            it++;
            result += double(*it);
            result /= 2;
        }
        return result;
    }
};