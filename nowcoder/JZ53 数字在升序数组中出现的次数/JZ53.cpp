class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        //二分查找
        int left = 0;
        int right = data.size() - 1;
        int mid = (left + right) / 2;
        int count = 0;
        while (left <= right)
        {
            if (data[mid] == k)
            {
                //统计次数
                count++;
                left = mid - 1;
                right = mid + 1;
                while (left >= 0)
                {
                    if (data[left--] == k)
                        count++;
                    else
                        break;
                }
                while (right < data.size())
                {
                    if (data[right++] == k)
                        count++;
                    else
                        break;
                }
                break;
            }
            else if (data[mid] < k)
            {
                left = mid;
                mid = (left + right) / 2;
            }
            else
            {
                right = mid;
                mid = (left + right) / 2;
            }
            if (left + 1 >= right)
                break;
        }
        return count;
    }
};