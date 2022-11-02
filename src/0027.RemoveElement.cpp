#include "headers.h"

class Solution {
 public:
  int removeElement(std::vector<int>& nums, int val) {
    int res{0};
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[res++] = nums[i];
      }
    }
    nums.resize(res);
    return res;
  }
};

TEST(removeElement, removeElement1) {
  Solution s;
  std::vector in{3, 2, 2, 3};
  std::vector res{2, 2};
  EXPECT_EQ(s.removeElement(in, 3), res.size());
  std::sort(res.begin(), res.end());
  std::sort(in.begin(), in.end());
  EXPECT_EQ(in, res);
}

TEST(removeElement, removeElement2) {
  Solution s;
  std::vector in{0, 1, 2, 2, 3, 0, 4, 2};
  std::vector res{0, 1, 4, 0, 3};
  EXPECT_EQ(s.removeElement(in, 2), res.size());
  std::sort(res.begin(), res.end());
  std::sort(in.begin(), in.end());
  EXPECT_EQ(in, res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
