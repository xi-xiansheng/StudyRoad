class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        int left = 0;
        int right = array.size() - 1;
        vector<int> vc;
        while (left < right)
        {
            if (array[left] + array[right] == sum)
            {
                vc.push_back(array[left]);
                vc.push_back(array[right]);
                break;
            }
            else if (array[left] + array[right] < sum)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return vc;
    }
};