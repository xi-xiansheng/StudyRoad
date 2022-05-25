class Solution {
public:
    /*int bfs(vector<vector<int>>& forest, pair<int, int> start, pair<int, int> target)
    {
        int rows = forest.size();
        int cols = forest[0].size();
        int step = 0;
        set<pair<int, int>> visited;
        visited.insert(start);
        queue<pair<int, int>> q;
        q.push(start);
        //vector<vector<bool>> visited(row, vector<bool>(col, false));
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                pair<int, int> cur = q.front();
                q.pop();
                //有效节点
                if(cur.first == target.first && cur.second == target.second)
                    return step;
                //有效相邻节点
                if(cur.first - 1 >= 0 && forest[cur.first - 1][cur.second] > 0 &&
                visited.find(make_pair(cur.first - 1, cur.second)) == visited.end())
                {
                    q.push(make_pair(cur.first - 1, cur.second));
                    visited.insert(make_pair(cur.first - 1, cur.second));
                }
                if(cur.second - 1 >= 0 && forest[cur.first][cur.second - 1] > 0 &&
                visited.find(make_pair(cur.first, cur.second - 1)) == visited.end())
                {
                    q.push(make_pair(cur.first, cur.second - 1));
                    visited.insert(make_pair(cur.first, cur.second - 1));
                }
                if(cur.second + 1 < cols && forest[cur.first][cur.second + 1] > 0 &&
                visited.find(make_pair(cur.first, cur.second + 1)) == visited.end())
                {
                    q.push(make_pair(cur.first, cur.second + 1));
                    visited.insert(make_pair(cur.first, cur.second + 1));
                }
                if(cur.first + 1 < rows && forest[cur.first + 1][cur.second] > 0 &&
                visited.find(make_pair(cur.first + 1, cur.second)) == visited.end())
                {
                    q.push(make_pair(cur.first + 1, cur.second));
                    visited.insert(make_pair(cur.first + 1, cur.second));
                }
            }
            step++;
        }
        return -1;
    }*/
    int bfs(vector<vector<int>>& forest, pair<int, int> start, pair<int, int> target)
    {
        int rows = forest.size();
        int cols = forest[0].size();
        int step = 0;
        //set<pair<int, int>> visited;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[start.first][start.second] = true;
        queue<pair<int, int>> q;
        q.push(start);
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                pair<int, int> cur = q.front();
                q.pop();
                //有效节点
                if (cur.first == target.first && cur.second == target.second)
                    return step;
                //有效相邻节点
                //visited.find(make_pair(cur.first - 1, cur.second)) == visited.end())  
                if (cur.first - 1 >= 0 && forest[cur.first - 1][cur.second] > 0 &&
                    visited[cur.first - 1][cur.second] == false)
                {
                    q.push(make_pair(cur.first - 1, cur.second));
                    //visited.insert(make_pair(cur.first - 1, cur.second));
                    visited[cur.first - 1][cur.second] = true;
                }
                if (cur.second - 1 >= 0 && forest[cur.first][cur.second - 1] > 0 &&
                    visited[cur.first][cur.second - 1] == false)
                    //visited.find(make_pair(cur.first, cur.second - 1)) == visited.end())
                {
                    q.push(make_pair(cur.first, cur.second - 1));
                    visited[cur.first][cur.second - 1] = true;
                    //visited.insert(make_pair(cur.first, cur.second - 1));
                }
                if (cur.second + 1 < cols && forest[cur.first][cur.second + 1] > 0 &&
                    visited[cur.first][cur.second + 1] == false)
                    //visited.find(make_pair(cur.first, cur.second + 1)) == visited.end())
                {
                    q.push(make_pair(cur.first, cur.second + 1));
                    visited[cur.first][cur.second + 1] = true;
                    //visited.insert(make_pair(cur.first, cur.second + 1));
                }
                if (cur.first + 1 < rows && forest[cur.first + 1][cur.second] > 0 &&
                    visited[cur.first + 1][cur.second] == false)
                    //visited.find(make_pair(cur.first + 1, cur.second)) == visited.end())
                {
                    q.push(make_pair(cur.first + 1, cur.second));
                    //visited.insert(make_pair(cur.first + 1, cur.second));
                    visited[cur.first + 1][cur.second] = true;
                }
            }
            step++;
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        map<int, pair<int, int>> order;
        int rows = forest.size();
        int cols = forest[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (forest[i][j] > 1)
                    order[forest[i][j]] = make_pair(i, j);
            }
        }
        int step = 0;
        pair<int, int> pos = make_pair(0, 0);
        for (auto e : order)
        {
            int res = bfs(forest, pos, e.second);
            if (res == -1)
                return -1;
            forest[e.second.first][e.second.second] = 1;
            step += res;
            pos = e.second;
        }
        return step;
    }
};




/*
BFS 模板

模板一：
如果不需要确定当前遍历到了哪一层，只需要访问完所有节点就可以时。

BFS 模板如下：


while queue 不空：
    cur = queue.pop()
    if cur 有效且未被访问过：
        进行处理
    for 节点 in cur 的所有相邻节点：
        if 该节点有效：
            queue.push(该节点)
模板二：
如果要确定当前遍历到了哪一层，需要知道最少移动步数时，BFS 模板如下。

这里增加了 level 表示当前遍历到二叉树中的哪一层了，也可以理解为在一个图中，现在已经走了多少步了。size 表示在当前遍历层有多少个元素，也就是队列中的元素数，我们把这些元素一次性遍历完，即把当前层的所有元素都向外走了一步。


level = 0
while queue 不空：
    size = queue.size()
    while (size --) {
        cur = queue.pop()
        if cur 有效且未被访问过：
            进行处理
        for 节点 in cur的所有相邻节点：
            if 该节点有效：
                queue.push(该节点)
    }
    level ++;

*/



