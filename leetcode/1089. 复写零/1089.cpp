class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int sz = arr.size();
        int i = 0;
        int j = sz - 1;
        int k = sz - 1;
        while (i <= j)
        {
            if (arr[i] == 0)
            {
                if (i == j)
                {
                    arr[k--] = 0;
                    j--;
                    break;
                }
                j--;
            }
            i++;
        }
        while (j >= 0 && k > j)
        {
            if (arr[j] == 0)
                arr[k--] = 0;
            arr[k--] = arr[j--];
        }
    }
};