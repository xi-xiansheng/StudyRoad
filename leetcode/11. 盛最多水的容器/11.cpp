class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        //int capacity = 0;
        int capacity = height[left] > height[right] ? (height[right] * (right - left)) : (height[left] * (right - left));
        while (left < right)
        {
            if (height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
            int low = height[left] > height[right] ? height[right] : height[left];
            if (capacity < low * (right - left))
            {
                capacity = low * (right - left);
            }
        }
        return capacity;
    }
};