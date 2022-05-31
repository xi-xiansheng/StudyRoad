class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*
        int ans = 0xffffffff;
        while(left <= right)
        {
            ans = ans & left;
            left++;
        }
        return ans;
        */
        if (left == right)
            return left;
        int ans = 0;
        int index = 31;
        while (index >= 0)
        {
            if ((left >> index) == (right >> index))
                index--;
            else
            {
                index++;
                ans = (right >> index) << index;
                break;
            }
        }
        return ans;
    }
};