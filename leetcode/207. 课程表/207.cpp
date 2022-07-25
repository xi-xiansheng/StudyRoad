class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        vector<unordered_set<int>> vs(numCourses);
        for (auto& Courses : prerequisites)
        {
            for (int i = Courses.size() - 1; i > 0; i--)
            {
                vs[Courses[i]].insert(Courses[i - 1]);
                degree[Courses[i - 1]] += 1;
            }
        }
        while (true)
        {
            int index = -1;
            for (int i = 0; i < numCourses; i++)
            {
                if (degree[i] == 0)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
                break;
            for (auto& e : vs[index])
            {
                degree[e] -= 1;
            }
            degree[index] = -1;
        }
        for (auto& e : degree)
        {
            if (e > 0)
                return false;
        }
        return true;
    }
};