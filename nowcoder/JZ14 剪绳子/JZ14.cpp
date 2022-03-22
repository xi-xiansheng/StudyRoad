/*class Solution {
    //空间复杂度O(N)
public:
    int Max(vector<int>& flag, int num)
    {
        if(num <= 4)
            return num;
        int max = 0;
        int ret;
        for(int i = 1;i <= num / 2; i++)
        {
            if(flag[i - 1] == 0)
                flag[i - 1] = Max(flag,i);
            ret = flag[i - 1];
            if(flag[num - i - 1] == 0)
                flag[num - i - 1] = Max(flag, num - i);
            ret *= flag[num - i - 1];
            if(ret > max)
                max = ret;
        }
        return max;
    }

    int cutRope(int number) {
        vector<int> flag;
        flag.resize(number);
        for(auto& e : flag)
        {
            e = 0;
        }
        if(number <= 3)
            return number - 1;
        return Max(flag, number);
    }
};*/
class Solution {
public:
    //最终简化为 2 / 3 的问题
    int cutRope(int number) {
        if (number <= 3)
            return number - 1;
        int count_3 = 0;
        int count_2 = 0;
        count_3 = number / 3;
        if (number % 3 == 1)
        {
            count_2 = 2;
            count_3--;
        }
        else if (number % 3 == 2)
        {
            count_2 = 1;
        }
        return int(pow(3, count_3) * pow(2, count_2));
    }
};