#include "headers.h"

class Solution {
 public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res;
    for (int i = 0; i < numRows; i++) {
      // заполняем очередную строку единицами
      res.push_back(std::vector<int>(i + 1, 1));
      for (int j = 1; j < i; j++) {
        // теперь вычисляем значения
        res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
      }
    }
    return res;
  }
};

TEST(SpiralOrder, SpiralOrder1) {
  Solution s;
  auto res = std::vector<std::vector<int>>{
      {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
  EXPECT_EQ(s.generate(5), res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}