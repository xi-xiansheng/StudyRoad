class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        //构建图
        vector<unordered_set<int>> graph(n + 1);
        vector<int> degree(n + 1, 0);
        for (auto& sequence : sequences)
        {
            int sz = sequence.size();
            for (int i = 0; i < sz - 1; i++)
            {
                graph[sequence[i]].insert(sequence[i + 1]);
                degree[sequence[i + 1]] += 1;
            }
        }
        //存储入度为0的点
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (degree[i] == 0)
                q.emplace(i);
        }
        while (!q.empty())
        {
            if (q.size() > 1)
                return false;
            int index = q.front();
            q.pop();
            for (auto& e : graph[index])
            {
                degree[e] -= 1;
                if (degree[e] == 0)
                    q.emplace(e);
            }
        }
        return true;
    }
};