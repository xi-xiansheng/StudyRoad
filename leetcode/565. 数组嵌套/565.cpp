/*class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int sz = nums.size();
        unordered_map<int, int> m;
        unordered_set<int> s;
        int ans = 0;
        for(int i = 0; i < sz; i++)
        {
            int next = nums[i];
            int ret = 0;
            while(s.count(next) == 0 && m.count(next) == 0)
            {
                ret++;
                s.insert(next);
                next = nums[next];
            }
            ret += m.count(next) == 0 ? 0 : m[next];
            if(m.count(nums[i]) == 0)
                m[nums[i]] = ret;
            ans = ans > ret ? ans : ret;
        }
        return ans;
    }
};*/
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;
        for (int i = 0; i < sz; i++)
        {
            int next = i;
            int ret = 0;
            while (nums[next] >= 0)
            {
                ret++;
                nums[next] = -nums[next] - 1;
                next = -nums[next] - 1;
            }
            ans = ans > ret ? ans : ret;
        }
        return ans;
    }
};