class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //每次与右上角元素比，加快效率
        int i = 0;
        int j = array[0].size() - 1;
        while (i < array.size() && j >= 0)
        {
            if (target < array[i][j])
                j--;
            else if (target > array[i][j])
                i++;
            else
                return true;
        }
        return false;
    }
};