class Solution {
public:
    void combination(const vector<int>& candidates, vector<int>& vc, int& index, int target)
    {
        if (index >= candidates.size() || target - candidates[index] < 0)
            return;
        vc.push_back(candidates[index]);
        if (target == candidates[index])
        {
            vvc.push_back(vc);
            vc.pop_back();
            return;
        }
        int newindex = index + 1;
        int sz = candidates.size();
        while (newindex < sz)
        {
            combination(candidates, vc, newindex, target - candidates[index]);
            while (newindex + 1 < sz && candidates[newindex] == candidates[newindex + 1])
            {
                newindex++;
            }
            newindex++;
        }
        vc.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        int sz = candidates.size();
        int index = 0;
        vector<int> vc;
        while (index < sz)
        {
            combination(candidates, vc, index, target);
            while (index + 1 < sz && candidates[index] == candidates[index + 1])
            {
                index++;
            }
            index++;
        }
        return vvc;
    }
private:
    vector<vector<int>> vvc;
};