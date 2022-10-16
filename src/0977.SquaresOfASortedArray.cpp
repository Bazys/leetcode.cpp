#include "headers.h"

class Solution {
 public:
  std::vector<int> sortedSquares(const std::vector<int>& nums) {
    auto l = nums.size();
    std::vector<int> res(l);
    int left{0};
    int right = l - 1;
    int i = right;
    while (left <= right) {
      auto powRight = std::pow(nums[right], 2);
      auto powLeft = std::pow(nums[left], 2);
      if (powRight > powLeft) {
        res[i] = powRight;
        right--;
      } else {
        res[i] = powLeft;
        left++;
      }
      i--;
    }
    return res;
  }
};

TEST(SortedSquares, SortedSquares1) {
  Solution s;
  std::vector<int> res{0, 1, 9, 16, 100};
  EXPECT_EQ(s.sortedSquares({-4, -1, 0, 3, 10}), res);
}

TEST(SortedSquares, SortedSquares2) {
  Solution s;
  std::vector<int> res{4, 9, 9, 49, 121};
  EXPECT_EQ(s.sortedSquares({-7, -3, 2, 3, 11}), res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}