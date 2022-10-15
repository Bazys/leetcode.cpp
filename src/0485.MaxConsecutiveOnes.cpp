#include "headers.h"

class Solution {
 public:
  int findMaxConsecutiveOnes(const std::vector<int>& nums) {
    int result{0}, max{0};
    for (auto el : nums) {
      if (el == 1) {
        result++;
      } else {
        max = std::max(max, result);
        result = 0;
      }
    }
    return std::max(max, result);
  }
};

TEST(findMaxConsecutiveOnes, findMaxConsecutiveOnes1) {
  Solution s;
  EXPECT_EQ(s.findMaxConsecutiveOnes({1, 1, 0, 1, 1, 1}), 3);
}

TEST(findMaxConsecutiveOnes, findMaxConsecutiveOnes2) {
  Solution s;
  EXPECT_EQ(s.findMaxConsecutiveOnes({1, 0, 1, 1, 0, 1}), 2);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}