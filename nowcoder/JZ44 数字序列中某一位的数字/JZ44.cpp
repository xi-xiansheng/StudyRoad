class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int findNthDigit(int n) {
        // write code here
        if (n <= 9)
            return n;

        size_t max = 9;
        int stage = 1;
        size_t  prev = 0;
        int remainder = 0;
        int result;
        int D_value;
        while (max < n)
        {
            //求级数
            stage++;
            prev = max;
            max = max + 9 * stage * (size_t)pow(10, stage - 1);
        }
        //D_value 表示与前一个级数（最大值 + 1）的差
        D_value = n - prev - 1;
        //remainder 表示余数
        remainder = D_value % stage;
        //若余数为0，则表明所求值位于第stage位
        if (remainder == 0)
            result = D_value / (stage * size_t(pow(10, stage - 1))) + 1;
        //余数不为0，则根据余数判断是第 stage - remainde位，
        //根据差值，通过取模，即 % stage*10^(stage-remainder)取出后stage - 1位
        else
            //result = (D_value / (stage * size_t(pow(10, stage - remainder - 1)))) % 10;
            result = (D_value % (stage * size_t(pow(10, stage - remainder)))) / (stage * size_t(pow(10, stage - remainder - 1)));
        //1000000000~1
        // 500000000~8
        return result;
    }
};