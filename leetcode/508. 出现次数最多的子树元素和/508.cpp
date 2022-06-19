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
    int FindFrequentTreeSum(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left = FindFrequentTreeSum(root->left);
        int right = FindFrequentTreeSum(root->right);
        int sum = left + right + root->val;
        res[sum] += 1;
        if (res[sum] > max)
            max = res[sum];
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        max = 0;
        vector<int> ans;
        FindFrequentTreeSum(root);
        for (auto& [key, value] : res)
        {
            if (value == max)
                ans.push_back(key);
        }
        return ans;
    }
private:
    map<int, int> res;
    int max;
};