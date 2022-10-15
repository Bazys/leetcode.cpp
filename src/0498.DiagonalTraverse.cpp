#include "headers.h"

class Solution {
 public:
  std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>> &mat) {

  }
};

TEST(findDiagonalOrder, findDiagonalOrder1) {
  Solution s;
  auto res = std::vector<int>{1, 2, 4, 7, 5, 3, 6, 8, 9};
  EXPECT_EQ(s.findDiagonalOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}), res);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}