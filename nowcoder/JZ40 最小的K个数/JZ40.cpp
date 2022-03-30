class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int, vector<int>, less<int>> q;
        int i = 0;
        while (i < k && i < input.size())
        {
            q.push(input[i]);
            i++;
        }
        while (i < input.size() && !q.empty())
        {
            if (input[i] < q.top())
            {
                q.pop();
                q.push(input[i]);
            }
            i++;
        }
        vector<int> vc;
        while (!q.empty())
        {
            vc.push_back(q.top());
            q.pop();
        }
        return vc;
    }
};