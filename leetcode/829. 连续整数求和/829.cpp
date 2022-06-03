class Solution {
public:
    /*int consecutiveNumbersSum(int n) {
        if(n == 1)
            return 1;
        int count = 1;
        int sum = 0;
        int begin = 1;
        int index = 1;
        while(index <= n / 2 + n % 2)
        {
            while(sum < n && index <= n / 2 + n % 2)
            {
                sum += index;
                index++;
            }
            if(sum == n)
            {
                count++;
                sum -= begin;
                begin++;
            }
            else
            {
                while(sum > n)
                {
                    sum -= begin;
                    begin++;
                }
            }
        }
        while(sum > n)
        {
            sum -= begin;
            begin++;
        }
        if(sum == n)
            count++;
        return count;
    }*/
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for (int k = 1; k * (k + 1) <= 2 * n; k++)
        {
            if (k % 2 == 1)
            {
                if (n % k == 0)
                    count++;
            }
            else
            {
                if (n % k != 0 && (2 * n) % k == 0)
                    count++;
            }
        }

        return count;
    }
};