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
        int newindex = index;
        int sz = candidates.size();
        while (newindex < sz)
        {
            combination(candidates, vc, newindex, target - candidates[index]);
            newindex++;
        }
        vc.pop_back();
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        int sz = candidates.size();
        int index = 0;
        vector<int> vc;
        while (index < sz)
        {
            combination(candidates, vc, index, target);
            index++;
        }
        return vvc;
    }
private:
    vector<vector<int>> vvc;
};