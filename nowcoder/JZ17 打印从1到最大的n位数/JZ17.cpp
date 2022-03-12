class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型 最大位数
     * @return int整型vector
     */
    vector<int> printNumbers(int n) {
        // write code here
        vector<int> vc;
        int num = 1;
        while (n--)
        {
            num *= 10;
        }
        vc.resize(num - 1);
        for (int i = 1; i < num; i++)
        {
            vc[i - 1] = i;
        }
        return vc;
    }
};