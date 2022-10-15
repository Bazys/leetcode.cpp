#include "headers.h"

class Solution {
 public:
  std::vector<int> spiralOrder(const std::vector<std::vector<int>>& mat) {
    // проверка на пустой массив
    if (mat.empty() || mat.size() == 0) {
      return {};
    }
    // сохраняем размеры массива
    auto N = mat.size();
    auto M = mat[0].size();
    // текущая позиция на очередной итерации
    int left{0}, top{0};
    int right = M - 1, bottom = N - 1;
    // в каком направлении движемся
    int direction{0};
    // здесь храним результат
    std::vector<int> res(N * M);
    int r{0};
    while (left <= right && top <= bottom) {
      if (direction == 0) {  // двигаемся слева направо
        for (int i = left; i <= right; i++) {
          res[r++] = mat[top][i];
        }
        direction = 1;  // дальше будем двигаться вниз
        top++;  // на следующей итерации будем обрабатывать ряд ниже
      } else if (direction == 1) {  // двигаемся сверху вниз
        for (int i = top; i <= bottom; i++) {
          res[r++] = mat[i][right];
        }
        direction = 2;  // дальше будем двигаться влево
        right--;  // на следующей итерации будем обрабатывать столбец левее
      } else if (direction == 2) {  // двигаемся справа налево
        for (int i = right; i >= left; i--) {
          res[r++] = mat[bottom][i];
        }
        direction = 3;  // дальше будем двигаться вверх
        bottom--;  // на следующей итерации будем обрабатывать ряд выше
      } else if (direction == 3) {  // двигаемся вверх
        for (int i = bottom; i >= top; i--) {
          res[r++] = mat[i][left];
        }
        direction = 0;  // дальше будем двигаться с права налево
        left++;  // на следующей итерации будем обрабатывать столбец правее
      }
    }
    return res;
  }
};

TEST(SpiralOrder, SpiralOrder1) {
  Solution s;
  auto res = std::vector<int>{1, 2, 3, 6, 9, 8, 7, 4, 5};
  EXPECT_EQ(s.spiralOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}), res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}