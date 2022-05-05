class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows && matrix[i][0] <= target; i++)
        {
            if (matrix[i][cols - 1] < target)
                continue;
            int left = 0;
            int right = cols - 1;
            while (left <= right)
            {
                if (matrix[i][left] > target)
                    return false;
                int mid = (left + right) / 2;
                if (matrix[i][mid] > target)
                    right = mid - 1;
                else if (matrix[i][mid] < target)
                    left = mid + 1;
                else
                    return true;
            }
        }
        return false;
    }
};