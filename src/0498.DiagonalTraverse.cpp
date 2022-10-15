#include "headers.h"

class Solution {
 public:
  std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>> &mat) {
    // проверка на пустой массив
    if (mat.empty() || mat.size() == 0) {
      return {};
    }
    // сохраняем размеры массива
    auto N = mat.size();
    auto M = mat[0].size();
    // текущая позиция на очередной итерации
    int row{0}, column{0};
    // в каком направлении движемся
    bool direction{true};
    // здесь храним результат
    std::vector<int> res(N * M);
    int r{0};
    // основной цикл перебора элементов массива
    while (row < N && column < M) {
      // прежде всего, добавляем текущий элемент в результат
      res[r++] = mat[row][column];
      // теперь смещаем курсор согласно текущему направлению
      // [i, j] -> [i - 1, j + 1] при движении вверх
      // [i, j] -> [i + 1][j - 1] при движении вниз
      int new_row = direction ? row - 1 : row + 1;
      int new_column = direction ? column + 1 : column - 1;
      // Проверяем что курсор после смещения не вышел за границы.
      // Если это так, значит надо скорректировать курсор и направление
      if (new_row < 0 || new_row == N || new_column < 0 || new_column == M) {
        if (direction) {  // движемся вверх
          // При движении вверх, при достижении границы (верхний ряд или
          // правый столбец), следующим стартовым элементом должен стать
          // элемент справа [i, j + 1], если мы не достигли правого
          // столбца, иначе им должен стать элемент снизу [i + 1, j]
          row += (column == M - 1 ? 1 : 0);
          column += (column < M - 1 ? 1 : 0);
        } else {  // движемся вниз
          // При движении вниз, при достижении границы (левый столбец или
          // нижний), следующим стартовым элементом должен стать
          // элемент справа [i, j + 1], если мы не достигли правого
          // столбца, иначе им должен стать элемент снизу [i + 1, j]
          column += (row == N - 1 ? 1 : 0);
          row += (row < N - 1 ? 1 : 0);
        }
        // меняем направление движения
        direction = not direction;
      } else {
        row = new_row;
        column = new_column;
      }
    }
    return res;
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