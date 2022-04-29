/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    Node* _construct(int sz, int sum)
    {

        if (sum == 0 || sum == sz * sz)
        {
            Node* _node = new Node(sum, false);
            _node->isLeaf = true;
            return _node;
        }
        return nullptr;
    }

    Node* construct(vector<vector<int>>& grid) {
        int sz = grid.size();
        Node* _node = new Node(false, false);

        int sum = 0;
        for (auto e : grid)
        {
            for (auto ee : e)
            {
                sum += ee;
            }
        }
        _node->val = sum;
        if (sz == 1 || (sum == 0 || sum == sz * sz))
        {
            _node->isLeaf = true;
            return _node;
        }
        int _sum = 0;
        vector<vector<int>> _array(sz / 2, vector<int>(sz / 2, 0));
        //topLeft
        for (int i = 0; i < sz / 2; i++)
        {
            for (int j = 0; j < sz / 2; j++)
            {
                _array[i][j] = grid[i][j];
                _sum += _array[i][j];
            }
        }
        if ((_node->topLeft = _construct(_sum, sz / 2)) == nullptr)
            _node->topLeft = construct(_array);
        //topRight
        _sum = 0;
        for (int i = 0; i < sz / 2; i++)
        {
            for (int j = sz / 2; j < sz; j++)
            {
                _array[i][j - sz / 2] = grid[i][j];
            }
        }
        if ((_node->topRight = _construct(_sum, sz / 2)) == nullptr)
            _node->topRight = construct(_array);
        //_node->topRight = construct(_array);
        //bottomLeft
        _sum = 0;
        for (int i = sz / 2; i < sz; i++)
        {
            for (int j = 0; j < sz / 2; j++)
            {
                _array[i - sz / 2][j] = grid[i][j];
            }
        }
        if ((_node->bottomLeft = _construct(_sum, sz / 2)) == nullptr)
            _node->bottomLeft = construct(_array);
        //_node->bottomLeft = construct(_array);

        //bottomRight
        _sum = 0;
        for (int i = sz / 2; i < sz; i++)
        {
            for (int j = sz / 2; j < sz; j++)
            {
                _array[i - sz / 2][j - sz / 2] = grid[i][j];
            }
        }
        if ((_node->bottomRight = _construct(_sum, sz / 2)) == nullptr)
            _node->bottomRight = construct(_array);
        //_node-> bottomRight = construct(_array);

        return _node;
    }
};