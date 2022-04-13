class Solution {
public:

    double find(const vector<int>& nums1, const vector<int>& nums2)
    {
        int index1 = 2 * nums1.size();
        int index2 = nums1.size() + nums2.size() - index1;
        int left1, left2, right1, right2;
        while (1)
        {
            if (index1 == 2 * nums1.size())
            {
                right1 = 0x7fffffff;
            }
            else
            {
                right1 = nums1[index1 / 2];
            }

            if (index1 == 0)
            {
                left1 = 0x80000000;
            }
            else
            {
                left1 = nums1[(index1 - 1) / 2];
            }

            if (index2 == 2 * nums2.size() + 1)
            {
                right2 = 0x7fffffff;
            }
            else
            {
                right2 = nums2[index2 / 2];
            }

            if (index2 == 0)
            {
                left2 = 0x80000000;
            }
            else
            {
                left2 = nums2[(index2 - 1) / 2];
            }

            if (left1 <= right2 && left2 <= right1)
            {
                double result = left1 > left2 ? left1 : left2;
                result += right1 < right2 ? right1 : right2;
                result /= 2;
                return result;
            }

            if (left1 > right2)
            {
                index2 += index1 / 2;
                index1 = index1 - index1 / 2;
            }

            else if (left2 > right1)
            {
                index2 -= index1 / 2;
                index1 = index1 + index1 / 2;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size())
            return find(nums2, nums1);
        return find(nums1, nums2);
    }
};