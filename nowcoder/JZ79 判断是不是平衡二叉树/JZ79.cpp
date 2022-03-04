class Solution {
public:
    bool _IsBalanced(TreeNode* root, int& depth)
    {
        if (root == nullptr)
        {
            depth = 0;
            return true;
        }
        int left_depth = 0;
        int right_depth = 0;
        if (_IsBalanced(root->left, left_depth) && _IsBalanced(root->right, right_depth))
        {
            if (left_depth - right_depth <= 1 && left_depth - right_depth >= -1)
            {
                depth += left_depth > right_depth ? left_depth + 1 : right_depth + 1;
                return true;
            }
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        //后序遍历--每个节点遍历一次
        int depth = 0;
        return _IsBalanced(pRoot, depth);
    }
};