#include <initializer_list>

#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H

struct ListNode {
    int val{};
    ListNode *next{};

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode(std::initializer_list<int> lst);
};

bool is_same_list(ListNode *l1, ListNode *l2);

#endif //LEETCODE_LISTNODE_H
