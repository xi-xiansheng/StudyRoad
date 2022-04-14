class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> numR;
        numR.resize(numRows);
        for (size_t i = 0; i < numRows; i++)
        {
            for (size_t j = 0; j <= i; j++)
            {
                (numR[i]).resize(i + 1);
                if (i == j || j == 0)
                {
                    numR[i][j] = 1;
                }
                else
                {
                    numR[i][j] = numR[i - 1][j - 1] + numR[i - 1][j];
                }
                std::cout << numR[i][j] << ' ';
            }
            std::cout << endl;
        }
        return numR;
    }
};