/*class Solution {
public:
    Solution(vector<int>& nums) {
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            pos[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        int sz = (pos[target]).size();
        return (pos[target])[rand() % sz];
    }
private:
    unordered_map<int, vector<int>> pos;
};*/
class Solution {
public:
    Solution(vector<int>& nums) {
        int sz = nums.size();
        _nums.resize(sz);
        for (int i = 0; i < sz; i++)
        {
            _nums[i] = nums[i];
        }
    }

    int pick(int target) {
        int count = 0;
        for (const auto& e : _nums)
        {
            if (e == target)
            {
                count++;
            }
        }
        int sz = _nums.size();
        count = rand() % count;
        for (int i = 0; i < sz; i++)
        {
            if (_nums[i] == target)
            {
                if (count == 0)
                    return i;
                count--;
            }
        }
        return sz - 1;
    }
private:
    vector<int> _nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */