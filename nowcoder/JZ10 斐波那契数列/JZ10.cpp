/*class Solution {
public:
    int Fibonacci(int n) {
        //方法一：迭代
        int fn_2 = 0;
        int fn_1 = 1;
        int fn = 0;
        while(n > 0)
        {
            fn = fn_1 + fn_2;
            fn_2 = n > 2 ? fn_1 : 0;
            fn_1 = fn;
            n--;
        }
        return fn;
    }
};*/
/*class Solution {
public:
    int Fibonacci(int n) {
        //方法二：递归
        if(n <= 1)
            return n;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};*/
class Solution {
public:
    int Fibonacci(int n) {
        //方法三：矩阵 时间复杂度：O(logN)
        int arr[2][2] = { 1, 1, 1, 0 };
        int tmp[2][2] = { 1, 1, 1, 0 };
        int k = (n - 1) / 2;
        while (k > 1)
        {
            tmp[0][0] = arr[0][0] + arr[0][1];
            tmp[0][1] = arr[0][0];
            tmp[1][0] = arr[1][0] + arr[1][1];
            tmp[1][1] = arr[1][0];
            for (size_t i = 0; i < 2; i++)
            {
                for (size_t j = 0; j < 2; j++)
                {
                    arr[i][j] = tmp[i][j];
                }
            }
            k--;
        }
        k = (n - 1) / 2;
        if (k >= 1)
        {
            tmp[0][0] = arr[0][0] * arr[0][0] + arr[0][1] * arr[1][0];
            tmp[0][1] = arr[0][0] * arr[0][1] + arr[0][1] * arr[1][1];
        }
        if (n % 2 == 0 && n > 2)
        {
            tmp[0][0] = tmp[0][0] + tmp[0][1];
        }
        return tmp[0][0];
    }
};