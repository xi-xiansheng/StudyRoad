/*class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
     /*    int duplicate(vector<int>& numbers) {
             // write code here
             //常规思路：排序
             std::sort(numbers.begin(), numbers.end());
             for(size_t i = 0; i < numbers.size(); ++i)
             {
                 if(numbers[i] == numbers[i + 1])
                     return numbers[i];
             }
             return -1;
         }
     };*/
class Solution {
public:
    int duplicate(vector<int>& numbers) {
        //
        vector<int> count;
        count.resize(numbers.size());
        for (auto& e : count)
        {
            e = 0;
        }
        for (const auto e : numbers)
        {
            count[e] += 1;
            if (count[e] >= 2)
                return e;
        }
        return -1;
    }
};
