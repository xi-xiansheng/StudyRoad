class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        //采用二分查找的方式，进行定位
        if (rotateArray.size() == 0)
            return 0;
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        while (rotateArray[left] >= rotateArray[right])
        {
            if (left + 1 == right)
            {
                mid = right;
                break;
            }
            mid = left + ((right - left) >> 1);
            //此时无法确定
            if (rotateArray[left] == rotateArray[mid] &&
                rotateArray[left] == rotateArray[right])
            {
                for (size_t i = left; i < right; i++)
                {
                    if (rotateArray[i] != rotateArray[i + 1])
                        return rotateArray[i + 1];
                }
            }
            //位于左半边
            if (rotateArray[left] > rotateArray[mid])
                right = mid;
            //位于右半边
            else
                left = mid;
        }
        return rotateArray[mid];
    }
};