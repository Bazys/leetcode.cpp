#include "headers.h"

class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) {
    int k{0};
    auto len = nums.size();
    for (int i = 0; k < len && i < len; i++) {
      if (nums[i] != 0) {
        std::swap(nums[k], nums[i]);
        k++;
      }
    }
  }
};

TEST(moveZeroes, moveZeroes1) {
  Solution s;
  auto in = std::vector<int>{0, 1, 0, 3, 12};
  auto res = std::vector<int>{1, 3, 12, 0, 0};
  s.moveZeroes(in);
  EXPECT_EQ(in, res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}