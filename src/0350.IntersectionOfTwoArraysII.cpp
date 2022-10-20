#include "headers.h"

class Solution {
 public:
  std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    //    auto last = std::unique(nums1.begin(), nums1.end());
    //    nums1.erase(last, nums1.end());
    //    last = std::unique(nums2.begin(), nums2.end());
    //    nums2.erase(last, nums2.end());
  }
};

TEST(intersect, intersect1) {
  Solution s;
  auto nums1 = std::vector<int>{1, 2, 2, 1};
  auto nums2 = std::vector<int>{2, 2};
  auto res = std::vector<int>{2, 2};
  EXPECT_EQ(s.intersect(nums1, nums2), res);
}

TEST(intersect, intersect2) {
  Solution s;
  auto nums1 = std::vector<int>{4, 9, 5};
  auto nums2 = std::vector<int>{9, 4, 9, 8, 4};
  auto res = std::vector<int>{4, 9};
  EXPECT_EQ(s.intersect(nums1, nums2), res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
