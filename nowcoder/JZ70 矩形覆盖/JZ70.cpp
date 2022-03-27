class Solution {
public:

    //计算排列组合数 即(m + n)! / (m! * n!)
    int PermutationCombination(int m, int n)
    {
        if (m < n)
        {
            m = m ^ n;
            n = m ^ n;
            m = m ^ n;
        }
        if (n == 0)
            return 1;
        int tmp = 1;
        long long NFactorial = 1;
        long long MFactorial = 1;
        long long MNFactorial = 1;
        while (tmp <= n)
        {
            NFactorial *= tmp;
            tmp++;
        }
        MFactorial = 1;
        /*while(tmp <= m)
        {
            MFactorial *= tmp;
            tmp++;
        }*/
        tmp = m + 1;
        MNFactorial = 1;
        while (tmp <= m + n)
        {
            MNFactorial *= tmp;

            tmp++;
        }
        return int(MNFactorial / NFactorial);
    }

    int rectCover(int number) {
        if (number == 0)
            return 0;
        //拆分为1和2的排列组合
        int count = 0;
        int count1 = 0;
        int count2 = 0;
        while (2 * count2 <= number)
        {
            count1 = number - 2 * count2;
            count += PermutationCombination(count1, count2);
            count2++;
        }
        return count;
    }
};