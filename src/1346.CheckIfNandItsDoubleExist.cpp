#include "headers.h"

class Solution {
 public:
  bool checkIfExist(const std::vector<int>& arr) {
    std::unordered_set<int> counter(arr.begin(), arr.end());
    int count{0};
    for (auto el : arr) {
      if (not el) count++;
      if (count > 1) return true;
    }
    for (auto el : arr) {
      if (el && counter.find(el * 2) != counter.end()) return true;
      if (el && el % 2 == 0 and counter.find(el / 2) != counter.end()) {
        return true;
      }
    }
    return false;
  }
};

TEST(checkIfExist, checkIfExist1) {
  Solution s;
  EXPECT_EQ(s.checkIfExist({10, 2, 5, 3}), true);
}

TEST(checkIfExist, checkIfExist2) {
  Solution s;
  EXPECT_EQ(s.checkIfExist({3, 1, 7, 11}), false);
}

TEST(checkIfExist, checkIfExist3) {
  Solution s;
  EXPECT_EQ(s.checkIfExist({-2, 0, 10, -19, 4, 6, -8}), false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
