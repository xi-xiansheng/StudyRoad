class Solution {
public:
    Solution(vector<vector<int>>& rects)
        :res(rects)
    {
        sum = 0;
        ans.resize(2);
        nums.push_back(0);
        for (auto& e : rects)
        {
            sum += (e[2] - e[0] + 1) * (e[3] - e[1] + 1);
            nums.push_back(sum);
        }
        e.seed(time(0));
    }

    vector<int> pick() {
        std::uniform_int_distribution<int> r(1, sum);
        long long index = r(e);
        int left = 1;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (index <= nums[mid] && index > nums[mid - 1])
                break;
            else if (index > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        cout << index << ", " << mid << endl;
        ans[0] = res[mid - 1][0] + (index - nums[mid - 1] - 1) % (res[mid - 1][2] - res[mid - 1][0] + 1);
        ans[1] = res[mid - 1][1] + (index - nums[mid - 1] - 1) / (res[mid - 1][2] - res[mid - 1][0] + 1);
        return ans;
    }
private:
    vector<vector<int>> res;
    vector<long long> nums;
    vector<int> ans;
    long long sum;
    std::default_random_engine e;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */