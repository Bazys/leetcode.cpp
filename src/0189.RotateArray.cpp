#include "headers.h"

class Solution {
 public:
  void rotate(std::vector<int>& nums, int k) {
    while (k > nums.size()) {
      k -= nums.size();
    }
    std::reverse(nums.begin(), nums.end() - k);
    std::reverse(nums.end() - k, nums.end());
    std::reverse(nums.begin(), nums.end());
  }
};

TEST(rotate, rotate1) {
  Solution s;
  std::vector<int> in{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> res{5, 6, 7, 1, 2, 3, 4};
  s.rotate(in, 3);
  EXPECT_EQ(in, res);
}

TEST(rotate, rotate2) {
  Solution s;
  std::vector<int> in{-1, -100, 3, 99};
  std::vector<int> res{3, 99, -1, -100};
  s.rotate(in, 2);
  EXPECT_EQ(in, res);
}

TEST(rotate, rotate3) {
  Solution s;
  std::vector<int> in{1, 2};
  std::vector<int> res{2, 1};
  s.rotate(in, 5);
  EXPECT_EQ(in, res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
