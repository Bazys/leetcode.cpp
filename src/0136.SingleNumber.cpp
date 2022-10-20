#include "headers.h"

class Solution {
 public:
  int singleNumber(const std::vector<int>& nums) {
    int ans = 0;
    for (auto x : nums) ans ^= x;
    return ans;
  }
};

TEST(singleNumber, singleNumber1) {
  Solution s;
  EXPECT_EQ(s.singleNumber({2, 2, 1}), 1);
}

TEST(singleNumber, singleNumber2) {
  Solution s;
  EXPECT_EQ(s.singleNumber({4, 1, 2, 1, 2}), 4);
}

TEST(singleNumber, singleNumber3) {
  Solution s;
  EXPECT_EQ(s.singleNumber({1}), 1);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
