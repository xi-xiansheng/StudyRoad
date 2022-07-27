class Solution {
public:
    string fractionAddition(string expression) {
        int sz = expression.size();
        long long numerator = 0;   //分子
        long long denominator = 1; //分母
        int cur = 0;
        while (cur < sz)
        {
            //读取分子
            int p = cur;
            while (cur < sz && expression[cur] != '/')
            {
                cur++;
            }
            long long _numerator = stoll(string(expression.begin() + p, expression.begin() + cur));
            //读取分母
            p = ++cur;
            while (cur < sz && expression[cur] != '+' && expression[cur] != '-')
            {
                cur++;
            }
            long long _denominator = stoll(string(expression.begin() + p, expression.begin() + cur));
            numerator = numerator * _denominator + denominator * _numerator;
            denominator *= _denominator;
        }
        if (numerator == 0)
            return "0/1";
        long long GCD = gcd(abs(numerator), denominator);
        return to_string(numerator / GCD) + "/" + to_string(denominator / GCD);
    }
};