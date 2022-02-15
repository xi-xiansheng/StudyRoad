//方法一
/*class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //开辟32大小的数组，用以记录每个二进制位1的个数
        int arr[32] = { 0 };
        for(size_t i = 0; i < numbers.size(); i++)
        {
            //每个元素依次统计
            for(size_t j = 0; j < 32; j++)
            {
                //统计每个二进制位1的数目
                arr[j] += (numbers[i] >> j) & 1;
            }
        }
        for(size_t j = 0; j < 32; j++)
        {
            if(arr[j] > numbers.size() / 2)
            {
                arr[j] = 1;
            }
            else
            {
                arr[j] = 0;
            }
        }
        //创建临时变量，将二进制转为 int
        int ret = 0;
        for(size_t j = 0; j < 32; j++)
        {
            ret = ret ^ (arr[j] << j);
        }
        return ret;
    }
};*/

//方法二
/*class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        std::sort(numbers.begin(),numbers.end());
        return numbers[numbers.size() / 2];
        //中间元素必定为所求元素
    }
};*/

//方法三
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 0;
        int pti = numbers[0];
        for (size_t i = 1; i < numbers.size(); i++)
        {
            if (count == 0)
            {
                pti = numbers[i];
            }
            if (numbers[i] == pti)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return pti;
    }
};