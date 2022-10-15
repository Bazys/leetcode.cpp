#include "headers.h"

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::map<int, int> diffIndex;
    for (int i = 0; i < nums.size(); ++i) {
      auto search = diffIndex.find(nums[i]);
      if (search != diffIndex.end()) {
        return std::vector<int>{search->second, i};
      } else {
        diffIndex.insert({target - nums[i], i});
      }
    }
    return {};
  }
};

TEST(twoSum, twoSum1) {
  Solution s;
  auto res = std::vector<int>{0, 1};
  EXPECT_EQ(s.twoSum({2, 7, 11, 15}, 9), res);
}
TEST(twoSum, twoSum2) {
  Solution s;
  auto res = std::vector<int>{1, 2};
  EXPECT_EQ(s.twoSum({3, 2, 4}, 6), res);
}
TEST(twoSum, twoSum3) {
  Solution s;
  auto res = std::vector<int>{0, 1};
  EXPECT_EQ(s.twoSum({3, 3}, 6), res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}