/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* TreeBuild(vector<int> nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = TreeBuild(nums, left, mid - 1);
        root->right = TreeBuild(nums, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        vector<int> vc;
        while (cur != nullptr)
        {
            vc.push_back(cur->val);
            cur = cur->next;
        }
        return TreeBuild(vc, 0, vc.size() - 1);
    }
};