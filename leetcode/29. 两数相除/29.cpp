class Solution {
public:
    size_t mypow_2(int n)
    {
        if (n < 32)
            return (size_t)(1 << n);
        return 0;
    }

    long _divide(long dividend, long divisor)
    {
        int ret = 0;
        int flag = 1;
        if (((dividend < 0) + (divisor < 0)) == 1)
        {
            flag = -1;
        }
        long _dividend = dividend;
        long _divisor = divisor;
        _dividend = (long)(abs(_dividend));
        _divisor = (long)(abs(_divisor));
        if (_dividend > ((long)0x7fffffff) && flag > 0)
            _dividend = ((long)0x7fffffff);
        if (_divisor > ((long)0x7fffffff) && flag > 0)
            _divisor = ((long)0x7fffffff);
        if (_dividend == 0 || _divisor == 1)
            return flag * _dividend;
        if (_dividend < _divisor && _dividend > 0)
            return 0;

        for (int i = 0; i < 32; i++)
        {
            if ((_divisor << i) == _dividend)
            {
                ret = mypow_2(i);
                break;
            }
            else if ((_divisor << i) > _dividend)
            {
                ret = mypow_2(i - 1) + divide(_dividend - (_divisor << (i - 1)), _divisor);
                break;
            }
        }
        return ret * flag;
    }

    int divide(int dividend, int divisor) {
        return (int)_divide((long)dividend, (long)divisor);
    }
};