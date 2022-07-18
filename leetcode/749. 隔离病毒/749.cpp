class Solution {
private:
    static constexpr int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
public:
    int containVirus(vector<vector<int>>& isInfected) {
        struct pair_hash
        {
            std::size_t operator() (const std::pair<int, int>& pair) const
            {
                return std::hash<int>()(pair.first) ^ std::hash<int>()(pair.second);
            }
        };
        int rows = isInfected.size();
        int cols = isInfected[0].size();
        int ans = 0;
        while (true)
        {
            //记录所有完整感染区域的相邻非感染区
            vector<std::unordered_set<pair<int, int>, pair_hash>> neibor;
            //记录所有完整感染区域所需的防火墙数量——下标一一对应
            vector<int> firewalls;
            //获取未建立防火墙的完整感染区域
            for (int x = 0; x < rows; x++)
            {
                for (int y = 0; y < cols; y++)
                {
                    if (isInfected[x][y] == 1)
                    {
                        //用以存储相邻感染区
                        queue<pair<int, int>> q;
                        //用以存储相邻非感染区
                        std::unordered_set<pair<int, int>, pair_hash> n0;
                        //记录每一完整区域所需的防火墙数量
                        int firewall = 0;
                        //为每个完整感染区域进行编号
                        int id = neibor.size() + 1;
                        q.push(make_pair(x, y));
                        //BFS  
                        while (!q.empty())
                        {
                            auto cur = q.front();
                            q.pop();
                            //进行赋值——表示已访问
                            isInfected[cur.first][cur.second] = -id;
                            //遍历相邻区域
                            for (int n = 0; n < 4; n++)
                            {
                                int i = cur.first + d[n][0];
                                int j = cur.second + d[n][1];
                                if (i >= 0 && i < rows && j >= 0 && j < cols)
                                {
                                    if (isInfected[i][j] == 1)
                                    {
                                        //为1表示该区域被感染且未被访问
                                        q.push(make_pair(i, j));
                                        //标记——防止重复添加
                                        isInfected[i][j] = -id;
                                    }
                                    else if (isInfected[i][j] == 0)
                                    {
                                        //为0表示该区域未感染
                                        firewall += 1;
                                        //插入该位置信息，方便后续感染以及面积计算等处理
                                        n0.insert(make_pair(i, j));
                                    }
                                }
                            }
                        }
                        //存储该完整区域所需的防火墙数目
                        firewalls.push_back(firewall);
                        //存储该感染区域影响的位置信息
                        neibor.push_back(n0);
                    }
                }
            }
            //获取影响面积最大且未建立防火墙的感染区域
            if (neibor.size() == 0)
                break;
            int idx = 0;
            int sz = neibor.size();
            for (int i = 0; i < sz; i++)
            {
                if (neibor[i].size() > neibor[idx].size())
                    idx = i;
            }
            ans += firewalls[idx];
            //重置操作
            for (int x = 0; x < rows; x++)
            {
                for (int y = 0; y < cols; y++)
                {
                    if (isInfected[x][y] < 0)
                    {
                        if (isInfected[x][y] == -idx - 1)
                            isInfected[x][y] = 2;
                        else
                            isInfected[x][y] = 1;
                    }
                }
            }
            //进行感染操作
            for (int i = 0; i < sz; i++)
            {
                if (i != idx)
                {
                    for (auto& idx : neibor[i])
                    {
                        isInfected[idx.first][idx.second] = 1;
                    }
                }
            }
        }
        return ans;
    }
};