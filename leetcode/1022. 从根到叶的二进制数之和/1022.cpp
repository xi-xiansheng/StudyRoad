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
 /*class Solution {
 public:
     int SumRoot(TreeNode* root, string s)
     {
         s += root->val + '0';
         if(root->left == nullptr && root->right == nullptr)
             return stoi(s, nullptr, 2);
         if(root->left == nullptr)
             return SumRoot(root->right, s);
         if(root->right == nullptr)
             return SumRoot(root->left, s);
         return SumRoot(root->left, s) + SumRoot(root->right, s);
     }

     int sumRootToLeaf(TreeNode* root) {
         return SumRoot(root, "");
     }
 };*/
class Solution {
public:
    int SumRoot(TreeNode* root, int sum)
    {
        sum = root->val + sum * 2;
        if (root->left == nullptr && root->right == nullptr)
            return sum;
        if (root->left == nullptr)
            return SumRoot(root->right, sum);
        if (root->right == nullptr)
            return SumRoot(root->left, sum);
        return SumRoot(root->left, sum) + SumRoot(root->right, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        return SumRoot(root, 0);
    }
};