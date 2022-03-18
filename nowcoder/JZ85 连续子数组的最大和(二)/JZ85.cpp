class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        int cur = 0;
        int sum = array[0];
        vector<int> vcur;
        vector<int> vsum;
        for (auto e : array)
        {
            cur += e;
            vcur.push_back(e);
            if (sum < cur)
            {
                sum = cur;
                vsum = vcur;
            }
            if (sum <= cur && vsum.size() < vcur.size())
            {
                vsum = vcur;
            }
            if (cur < 0)
            {
                vcur.resize(0);
                cur = 0;
            }
        }
        return vsum;
    }
};