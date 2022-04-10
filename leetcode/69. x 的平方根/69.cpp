/*class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0)
            return 0;
        long long tmp_x = x;
        long long i = 1;
        while((i + 1) * (i + 1) <= x)
        {
            i++;
        }
        return i;
    }
};*/

/*class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0)
            return 0;
        /*
        //超出时间限制
        long long tmp_x = x;
        for(long long i = x / 2 + x % 2; i > 0; i--)
        {
            if(i * i <= x)
                return i;
        }
        return 0;*/
        //1978959248
        /*long long xret = x;
        long long i = 1;
        while(i * i < xret)
        {
            i *= 2;
        }
        if(i * i == xret)
            return i;
        i /= 2;
        while((i + 1) * (i + 1) <= xret)
        {
            i++;
        }
        return i;
    }
};*/
class Solution {
public:
    int mySqrt(int x) {
        //牛顿·迭代法
        if (x <= 0)
            return 0;
        long answer = x;
        while (answer * answer > x)
        {
            answer = (answer + x / answer) / 2;
        }
        return answer;
    }
};
