#include "headers.h"

class Solution {
public:
    int removeDuplicates(std::vector<int> &nums) {
        int res{1};
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[i - 1]) nums[res++] = nums[i];
        nums.resize(res);
        return res;
    }
};

TEST(dominantIndex, dominantIndex1) {
    Solution s;
    std::vector in{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::vector res{0, 1, 2, 3, 4};
    EXPECT_EQ(s.removeDuplicates(in), 5);
    EXPECT_EQ(in, res);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}