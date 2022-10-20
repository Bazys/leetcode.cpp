#include "headers.h"

class Solution {
 public:
  int smallestEvenMultiple(int n) {
    if ((n & 1) == 0) {
      return n;
    }
    return n * 2;
  }
};

TEST(smallestEvenMultiple, SmallestEvenMultiple1) {
  Solution s;
  EXPECT_TRUE(s.smallestEvenMultiple(5) == 10);
}

TEST(smallestEvenMultiple, SmallestEvenMultiple2) {
  Solution s;
  EXPECT_TRUE(s.smallestEvenMultiple(6) == 6);
}
