#include "listnode.h"

bool is_same_list(ListNode *l1, ListNode *l2)
{
    while (l1 != nullptr && l2 != nullptr && l1->val == l2->val)
    {
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 == l2) {
        return true;
    } else {
        return false;
    }
}

ListNode::ListNode(std::initializer_list<int> lst)  {
    if (lst.size()) {
        auto iter = lst.begin();
        val = *iter++;
        for (ListNode *cur = this; iter != lst.end(); cur = cur->next) {
            cur->next = new ListNode(*iter++);
        }
    }
}