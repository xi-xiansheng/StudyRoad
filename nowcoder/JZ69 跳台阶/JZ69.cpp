class Solution {
public:
    /*int jumpFloor(int number) {
        if(number <= 2)
            return number;
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }*/
    int jumpFloor(int number)
    {
        int fn_1 = 1;
        int fn_2 = 0;
        int fn = 0;
        while (number--)
        {
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }

};