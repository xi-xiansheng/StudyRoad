class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> reOrderArrayTwo(vector<int>& array) {
        // write code here
        for (size_t i = 0; i < array.size(); i++)
        {
            if (array[i] % 2 == 0)
            {
                int j = i + 1;
                while (j < array.size() && array[j] % 2 == 0)
                {
                    j++;
                }
                if (j == array.size())
                    break;
                else
                    std::swap(array[i], array[j]);
            }
        }
        return array;
    }
};