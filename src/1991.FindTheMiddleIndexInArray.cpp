#include "headers.h"

class Solution {
public:
    int findMiddleIndex(const std::vector<int> &nums) {
        auto n = nums.size();
        if (n == 1) return 0;
        int right{0};
        int left{0};
        right = accumulate(nums.begin(), nums.end(), right);
        for (int i = 0; i < n; ++i) {
            right -= nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};

TEST(findMiddleIndex, findMiddleIndex1) {
    Solution s;
    EXPECT_TRUE(s.findMiddleIndex({2, 3, -1, 8, 4}) == 3);
}

TEST(findMiddleIndex, findMiddleIndex2) {
    Solution s;
    EXPECT_TRUE(s.findMiddleIndex({1, -1, 4}) == 2);
}

TEST(findMiddleIndex, findMiddleIndex3) {
    Solution s;
    EXPECT_TRUE(s.findMiddleIndex({4, 0}) == 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}