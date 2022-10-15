#include "headers.h"

class Solution {
public:
    int dominantIndex(const std::vector<int> &nums) {
        auto maxIndex = std::max_element(nums.begin(), nums.end()) - nums.begin();
        int max = nums[maxIndex];
        auto n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != max && max < 2 * nums[i]) {
                return -1;
            }
        }
        return maxIndex;
    }
};

TEST(dominantIndex, dominantIndex1) {
    Solution s;
    EXPECT_EQ(s.dominantIndex({3, 6, 1, 0}), 1);
}

TEST(dominantIndex, dominantIndex2) {
    Solution s;
    EXPECT_EQ(s.dominantIndex({1, 2, 3, 4}), -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}