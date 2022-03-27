class Solution {
public:
    /*bool IsUglyNumber(int n)
    {
        while(n % 2 == 0)
        {
            n /= 2;
        }
        while(n % 3 == 0)
        {
            n /= 3;
        }
        while(n % 5 == 0)
        {
            n /= 5;
        }
        return n == 1;
    }*/
    int MinNumber(int number1, int number2, int number3)
    {
        int min = number1 < number2 ? number1 : number2;
        min = min < number3 ? min : number3;
        return min;
    }
    int GetUglyNumber_Solution(int index) {
        //暴力求解法——无法通过
        /*int count = 0;
        int number = 1;
        while(count <= index)
        {
            if(IsUglyNumber(number))
                count++;
            if(count == index)
                break;
            number++;
        }
        return number;*/

        //方法二：
        if (index <= 0)
            return 0;
        vector<int> vc;
        vc.resize(index);
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        vc.push_back(1);
        int count = 1;
        int MaxUglyNumber = 1;
        while (count < index)
        {
            while (vc[index2] * 2 <= MaxUglyNumber)
            {
                index2++;
            }
            while (vc[index3] * 3 <= MaxUglyNumber)
            {
                index3++;
            }
            while (vc[index5] * 5 <= MaxUglyNumber)
            {
                index5++;
            }
            MaxUglyNumber = MinNumber(vc[index2] * 2, vc[index3] * 3, vc[index5] * 5);
            vc.push_back(MaxUglyNumber);
            count++;
        }
        return MaxUglyNumber;
    }
};