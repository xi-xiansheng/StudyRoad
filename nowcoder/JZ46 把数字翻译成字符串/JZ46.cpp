class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int ResultCount(const string& nums, int index)
    {
        if (index >= nums.size() || nums[index] == '\0' || nums[index] == '0')
            return 0;
        //表示仅剩1个元素
        if (index + 1 >= nums.size())
            return 1;
        //当前数字大于等于3，只会有一种结果
        if (nums[index] >= '3')
            return ResultCount(nums, index + 1);
        //为10或20，仅有一种结果
        if (nums[index + 1] == '0')
            return index == nums.size() - 2 ? 1 : ResultCount(nums, index + 2);
        //为27/28/29，则2必定单独
        if (nums[index] == '2' && nums[index + 1] >= '7')
            return index == nums.size() - 2 ? 1 : ResultCount(nums, index + 2);
        if (index == nums.size() - 2)
            return 2;
        return  ResultCount(nums, index + 1) + ResultCount(nums, index + 2);
    }

    int solve(string nums) {
        // write code here
        return ResultCount(nums, 0);
    }
};