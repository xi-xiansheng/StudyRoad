class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //开辟32大小的数组，用以记录每个二进制位1的个数
        int arr[32] = { 0 };

        for (size_t i = 0; i < nums.size(); i++)
        {
            //每个元素依次统计
            for (size_t j = 0; j < 32; j++)
            {
                //统计每个二进制位1的数目
                arr[j] += (nums[i] >> j) & 1;
            }
        }
        //每个元素 % 3 的余数，即为所求元素对应二进制位的数字（ 0 /  1）
        for (size_t j = 0; j < 32; j++)
        {
            arr[j] %= 3;
        }
        //创建临时变量，将二进制转为 int 
        int ret = 0;
        for (size_t j = 0; j < 32; j++)
        {
            ret = ret ^ (arr[j] << j);
        }
        return ret;
    }
};