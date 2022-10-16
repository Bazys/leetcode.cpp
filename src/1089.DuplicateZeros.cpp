#include "headers.h"

class Solution {
 public:
  void duplicateZeros(std::vector<int>& A) {
    int n = A.size(), j = n + count(A.begin(), A.end(), 0);
    for (int i = n - 1; i >= 0; --i) {
      if (--j < n) A[j] = A[i];
      if (A[i] == 0 && --j < n) A[j] = 0;
    }
  }
};

TEST(DuplicateZeros, duplicateZeros1) {
  Solution s;
  std::vector<int> in{1, 0, 2, 3, 0, 4, 5, 0};
  std::vector<int> res{1, 0, 0, 2, 3, 0, 0, 4};
  s.duplicateZeros(in);
  EXPECT_EQ(in, res);
}

TEST(DuplicateZeros, duplicateZeros2) {
  Solution s;
  std::vector<int> in{1, 2, 3};
  std::vector<int> res{1, 2, 3};
  s.duplicateZeros(in);
  EXPECT_EQ(in, res);
}

TEST(DuplicateZeros, duplicateZeros3) {
  Solution s;
  std::vector<int> in{1, 0, 0, 3, 0};
  std::vector<int> res{1, 0, 0, 0, 0};
  s.duplicateZeros(in);
  EXPECT_EQ(in, res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}