class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        /*priority_queue<int, vector<int>, std::less<int>> q;
        int sz = nums.size();
        for(int i = 0; i < sz - 1; i++)
        {
            for(int j = i + 1; j < sz; j++)
            {
                if(q.size() < k)
                    q.push(abs(nums[i] - nums[j]));
                else
                {
                    if(abs(nums[i] - nums[j]) < q.top())
                    {
                        q.pop();
                        q.push(abs(nums[i] - nums[j]));
                    }
                }
            }
        }*/
        int sz = nums.size();
        std::sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[sz - 1] - nums[0];
        int ans = 0;
        while (left <= right)
        {
            int i = 0;
            int count = 0;
            int mid = (left + right) / 2;
            for (int j = 0; j < sz; j++)
            {
                while (nums[j] - nums[i] > mid)
                {
                    i++;
                }
                count += j - i;
            }
            if (count >= k)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};