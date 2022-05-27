class Solution {
public:
    int trailingZeroes(int n) {
        int count_2 = 0;
        int count_5 = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = i;
            while (tmp % 2 == 0)
            {
                count_2++;
                tmp /= 2;
            }
            while (tmp % 5 == 0)
            {
                count_5++;
                tmp /= 5;
            }
        }
        return count_2 < count_5 ? count_2 : count_5;
    }
};
/*class Solution {
public:
    int trailingZeroes(int n) {
        int count_2 = 0;
        int count_5 = 0;
        unordered_map<int, int> m2;
        unordered_map<int, int> m5;

        for(int i = 1; i <= n; i++)
        {
            int tmp = i;
            if(tmp % 2 == 0)
            {
                int num = m2[tmp / 2];
                m2[tmp] = num + 1;
                count_2 += num + 1;
            }
            if(tmp % 5 == 0)
            {
                int num = m5[tmp / 5];

                m5[tmp] = num + 1;
                count_5 += num + 1;
            }
        }
        return count_2 < count_5 ? count_2 : count_5;
    }
};*/
