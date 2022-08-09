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
    ListNode* ListReverse(ListNode* head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode* newhead = head, * cur = head->next;
        while (cur)
        {
            ListNode* tmp = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = tmp;
        }
        head->next = nullptr;
        return newhead;
    }

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = ListReverse(slow->next);
        slow->next = nullptr;
        //Æ´½Ó
        ListNode* cur = head;
        while (cur && fast)
        {
            ListNode* tmp = cur->next;
            ListNode* frtmp = fast->next;
            cur->next = fast;
            fast->next = tmp;
            cur = tmp;
            fast = frtmp;
        }
    }
};
/*class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
        vector<ListNode*> v;
        while(head)
        {
            v.push_back(head);
            head = head->next;
        }
        int left = 0, right = v.size() - 1;
        for(; left < right; left++, right--)
        {
            v[left]->next = v[right];
            v[right]->next = v[left + 1];
        }
        v[left]->next = nullptr;
    }
};*/