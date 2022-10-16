#include "headers.h"

class Solution {
 public:
  int findNumbers(const std::vector<int>& nums) {
    int res{0};
    for (const auto& num : nums) {
      res += static_cast<int>(log10(num)) & 1;
    }
    return res;
  }
};

TEST(FindNumbers, findNumbers1) {
  Solution s;
  EXPECT_EQ(s.findNumbers({12, 345, 2, 6, 7896}), 2);
}

TEST(FindNumbers, findNumbers2) {
  Solution s;
  EXPECT_EQ(s.findNumbers({555, 901, 482, 1771}), 1);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}