class Solution {
public:
    void slove(string equation, int& cv, int& sum, bool flag)
    {
        if (equation[0] != '-' && equation[0] != '+')
            equation = "+" + equation;
        int factor = 1;
        if (flag == false)
            factor = -1;
        int sz = equation.size();
        for (int i = 0; i < sz; i++)
        {
            int start = i++;
            while (i < sz && equation[i] != '-' && equation[i] != '+')
            {
                i++;
            }
            if (equation[i - 1] == 'x')
            {
                if (i - start == 2)
                {
                    if (equation[start] == '-')
                        cv -= 1 * factor;
                    else
                        cv += 1 * factor;
                }
                else
                    cv += stoi(string(equation.begin() + start, equation.begin() + i - 1)) * factor;
            }
            else
            {
                sum -= stoi(string(equation.begin() + start, equation.begin() + i)) * factor;
            }
            i--;
        }
    }
    string solveEquation(string equation) {
        int cv = 0;
        int sum = 0;
        int sz = equation.size();
        for (int i = 0; i < sz; i++)
        {
            if (equation[i] == '=')
            {
                slove(string(equation.begin(), equation.begin() + i), cv, sum, true);
                slove(string(equation.begin() + i + 1, equation.end()), cv, sum, false);
                break;
            }
        }
        if (cv == 0 && sum == 0)
            return "Infinite solutions";
        else if (cv == 0)
            return "No solution";
        else
            return "x=" + to_string(sum / cv);
    }
};