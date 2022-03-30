class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vc;
        //vc.resize(2);
        multimap<int, int> ms;
        int index = 0;
        while (index < nums.size())
        {
            auto it = ms.find(nums[index]);
            if (it == ms.end())
            {
                ms.insert(make_pair(nums[index], index));
            }
            else if (2 * nums[index] == target)
            {
                vc.push_back(index);
                vc.push_back((*it).second);
                return vc;
            }
            index++;
        }
        for (auto e : ms)
        {
            auto it = ms.find(target - e.first);
            if (it != ms.end())
            {
                vc.push_back(e.second);
                vc.push_back((*it).second);
                return vc;
            }
        }
        return vc;
    }
};