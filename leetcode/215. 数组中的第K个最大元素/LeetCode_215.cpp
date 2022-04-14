/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //方法一：排序
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};*/

/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //方法二：建大堆
        priority_queue<int> pq;
        for(size_t i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
       while(--k)
       {
           pq.pop();
       }
        return pq.top();
    }
};*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //方法三：建k个数的小堆
        priority_queue<int, vector<int>, greater<int>> pq;
        for (size_t i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (size_t i = k; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};