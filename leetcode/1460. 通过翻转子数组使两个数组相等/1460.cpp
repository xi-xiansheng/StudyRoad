class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        /*
        ** 解题思路：冒泡排序
        ** 只要元素相同， 必定可得到相同数组
        */
        map<int, int> m;
        for (int i = 0, sz = target.size(); i < sz; i++)
        {
            m[target[i]] -= 1;
            m[arr[i]] += 1;
        }
        for (auto [k, v] : m)
        {
            if (v != 0)  return false;
        }
        return true;
    }
};