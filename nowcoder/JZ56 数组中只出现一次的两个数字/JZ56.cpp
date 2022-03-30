class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        //位运算
        int flag = 0;
        for (auto e : array)
        {
            flag ^= e;
        }
        //找到首位为1的二进制位
        int i = 0;
        while (((flag >> i) & 1) == 0)
        {
            i++;
        }
        //
        flag = flag & (1 << i);
        vector<int> vc;
        vc.resize(2);
        for (auto e : array)
        {
            if (e & flag)
            {
                vc[0] ^= e;
            }
            else
            {
                vc[1] ^= e;
            }
        }
        if (vc[0] > vc[1])
            std::swap(vc[0], vc[1]);
        return vc;
    }
};