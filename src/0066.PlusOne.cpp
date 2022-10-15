#include "headers.h"

class Solution {
public:
    std::vector<int> plusOne(std::vector<int> &digits) {
        auto n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        std::vector<int> res(n + 1, 0);
        res[0] = 1;
        return res;
    }
};

TEST(plusOne, plusOne1) {
    Solution s;
    auto in = std::vector<int>{1, 2, 3};
    auto res = std::vector<int>{1, 2, 4};
    EXPECT_EQ(s.plusOne(in), res);
}

TEST(plusOne, plusOne2) {
    Solution s;
    auto in = std::vector<int>{4, 3, 2, 1};
    auto res = std::vector<int>{4, 3, 2, 2};
    EXPECT_EQ(s.plusOne(in), res);
}

TEST(plusOne, plusOne3) {
    Solution s;
    auto in = std::vector<int>{9};
    auto res = std::vector<int>{1, 0};
    EXPECT_EQ(s.plusOne(in), res);
}

TEST(plusOne, plusOne4) {
    Solution s;
    auto in = std::vector<int>{9, 9, 9, 9};
    auto res = std::vector<int>{1, 0, 0, 0, 0};
    EXPECT_EQ(s.plusOne(in), res);
}

TEST(plusOne, plusOne5) {
    Solution s;
    auto in = std::vector<int>{9, 9, 8, 9, 9};
    auto res = std::vector<int>{9, 9, 9, 0, 0};
    EXPECT_EQ(s.plusOne(in), res);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}