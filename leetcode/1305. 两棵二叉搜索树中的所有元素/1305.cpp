/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void InsertElements(TreeNode* root, vector<int>& _list)
    {
        if (root == nullptr)
            return;
        InsertElements(root->left, _list);
        _list.push_back(root->val);
        InsertElements(root->right, _list);
        return;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        InsertElements(root1, list1);
        vector<int> list2;
        InsertElements(root2, list2);
        int i = 0, j = 0;
        int sz1 = list1.size();
        int sz2 = list2.size();
        vector<int> list;
        while (i < sz1 && j < sz2)
        {
            if (list1[i] < list2[j])
                list.push_back(list1[i++]);
            else
                list.push_back(list2[j++]);
        }
        while (i < sz1)
        {
            list.push_back(list1[i++]);
        }
        while (j < sz2)
        {
            list.push_back(list2[j++]);
        }
        return list;
    }
};