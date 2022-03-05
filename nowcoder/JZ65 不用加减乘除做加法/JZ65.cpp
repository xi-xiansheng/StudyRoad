class Solution {
public:
    int Add(int num1, int num2) {
        if (num1 == 0)
            return num2;
        if (num2 == 0)
            return num1;
        //位运算——三步法
        //异或
        int result1 = num1 ^ num2;
        //按位与
        int result2 = (num1 & num2) << 1;
        //将前两步结果相加
        return Add(result1, result2);
    }
};