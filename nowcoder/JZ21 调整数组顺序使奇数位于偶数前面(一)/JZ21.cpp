class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here 
        //直接插入思想
        int pos = 0;
        while (pos < array.size())
        {
            if (array[pos] % 2 == 1)
            {
                int cur = pos;
                int tmp = array[pos];
                while (cur > 0 && array[cur - 1] % 2 == 0)
                {
                    array[cur] = array[cur - 1];
                    cur--;
                }
                array[cur] = tmp;
            }
            pos++;
        }
        return array;
    }
};