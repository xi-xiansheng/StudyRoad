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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* newhead = nullptr;
        ListNode* newtail = nullptr;
        int index = 0;
        while (lists.size())
        {
            index = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] && (lists[i])->val < (lists[index])->val)
                {
                    index = i;
                }
                else if (lists[i] == nullptr)
                {
                    std::swap(lists[i], lists[lists.size() - 1]);
                    i--;
                    lists.resize(lists.size() - 1);
                }
            }
            if (newhead == nullptr && lists.size())
            {
                newhead = newtail = lists[index];
            }
            else if (lists.size())
            {
                newtail->next = lists[index];
                newtail = lists[index];
            }
            else
            {
                break;
            }
            lists[index] = (lists[index])->next;
            newtail->next = nullptr;
        }
        return newhead;
    }
};