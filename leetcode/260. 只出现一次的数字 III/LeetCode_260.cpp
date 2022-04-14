class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int flag = 0;
        vector<int> num;
        num.resize(2);
        num[0] = num[1] = 0;
        //找出异或的结果
        for (size_t i = 0; i < nums.size(); i++)
        {
            flag ^= nums[i];
        }
        //必定有一位为1，并找出其第一个1所在位置
        while (flag % 2 != 1 && flag % 2 != -1)
        {
            num[0]++;
            flag = flag >> 1;
        }
        //其他位置为0
        flag = 1 << num[0];
        num[0] = 0;
        //所有元素中，按位与结果只有两种，且那两个出现一次的元素，结果也必不相同
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] & flag)
            {
                num[0] = nums[i] ^ num[0];
            }
            else
            {
                num[1] = nums[i] ^ num[1];
            }
        }
        return num;
    }
};