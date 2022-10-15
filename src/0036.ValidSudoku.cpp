#include "headers.h"

class Solution {
 public:
  bool isValidSudoku(const std::vector<std::vector<char>>& board) {
    int N = 9;
    std::vector<int> rows(N), cols(N), squares(N);
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        if (board[r][c] == '.') continue;
        int val = board[r][c] - '0';
        int sPos = (r / 3) * 3 + (c / 3);
        if (getBit(rows[r], val) || getBit(cols[c], val) ||
            getBit(squares[sPos], val))
          return false;
        rows[r] |= 1 << val;
        cols[c] |= 1 << val;
        squares[sPos] |= 1 << val;
      }
    }
    return true;
  }
  int getBit(int x, int k) { return (x >> k) & 1; }
};

TEST(removeDuplicates, removeDuplicates1) {
  Solution s;
  std::vector<std::vector<char>> board{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  EXPECT_EQ(s.isValidSudoku(board), true);
}
TEST(removeDuplicates, removeDuplicates2) {
  Solution s;
  std::vector<std::vector<char>> board{
      {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  EXPECT_EQ(s.isValidSudoku(board), false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}