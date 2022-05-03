#include "headers.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy{0};
        auto curr = &dummy;

        auto carry = 0;
        while (l1 || l2 || carry) {
            auto a = l1 ? l1->val : 0, b = l2 ? l2->val : 0;
            auto val = carry + a + b;
            curr->next = new ListNode(val % 10);
            carry = val / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            curr = curr->next;
        }

        return dummy.next;
    }
};

TEST(addTwoNumbers, addTwoNumbers_1) {
    Solution s;
    ListNode l1{2, 4, 3};
    ListNode l2{5, 6, 4};
    ListNode ans{7, 0, 8};
    EXPECT_TRUE(is_same_list(s.addTwoNumbers(&l1, &l2), &ans));
}

TEST(addTwoNumbers, addTwoNumbers_2) {
    Solution s;
    ListNode l1{0, 1};
    ListNode l2{0, 1, 2};
    ListNode ans{0, 2, 2};
    EXPECT_TRUE(is_same_list(s.addTwoNumbers(&l1, &l2), &ans));
}

TEST(addTwoNumbers, addTwoNumbers_3) {
    Solution s;
    ListNode l1{};
    ListNode l2{0, 1};
    ListNode ans{0, 1};
    EXPECT_TRUE(is_same_list(s.addTwoNumbers(&l1, &l2), &ans));
}

TEST(addTwoNumbers, addTwoNumbers_4) {
    Solution s;
    ListNode l1{9, 9};
    ListNode l2{1};
    ListNode ans{0, 0, 1};
    EXPECT_TRUE(is_same_list(s.addTwoNumbers(&l1, &l2), &ans));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}