#include "headers.h"

class Solution {
 public:
  bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> counter;
    for (auto& el : nums) {
      if (counter.find(el) == counter.end()) {
        counter.insert(el);
      } else {
        return true;
      }
    }
    return false;
  }
};

TEST(containsDuplicate, containsDuplicate1) {
  Solution s;
  EXPECT_EQ(s.containsDuplicate({1, 2, 3, 1}), true);
}

TEST(containsDuplicate, containsDuplicate2) {
  Solution s;
  EXPECT_EQ(s.containsDuplicate({1, 2, 3, 4}), false);
}

TEST(containsDuplicate, containsDuplicate3) {
  Solution s;
  EXPECT_EQ(s.containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
