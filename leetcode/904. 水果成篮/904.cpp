class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //»¬¶¯´°¿Ú
        map<int, int> m;
        int ans = 0;
        int start = 0, index = 0;
        for (int sz = fruits.size(); index < sz; index++)
        {
            m[fruits[index]] += 1;
            if (m.size() < 3)
                ans = std::max(ans, index - start + 1);
            else
            {
                while (true)
                {
                    if ((--m[fruits[start]]) == 0)
                    {
                        m.erase(fruits[start++]);
                        break;
                    }
                    start++;
                }
            }
        }
        ans = std::max(ans, index - start);
        return ans;
    }
};