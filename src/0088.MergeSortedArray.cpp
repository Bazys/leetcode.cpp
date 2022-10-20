#include "headers.h"

class Solution {
 public:
  void merge(std::vector<int>& nums1, const int& m, std::vector<int>& nums2,
             const int& n) {
    int i = m + n - 1;
    int end1 = m - 1;
    int end2 = n - 1;
    while (end2 >= 0) {
      if (end1 >= 0 and nums1[end1] > nums2[end2]) {
        std::swap(nums1[i--], nums1[end1--]);
      } else {
        std::swap(nums1[i--], nums2[end2--]);
      }
    }
  }
};

TEST(merge, merge1) {
  Solution s;
  auto nums1 = std::vector<int>{1, 2, 3, 0, 0, 0};
  auto nums2 = std::vector<int>{2, 5, 6};
  auto res = std::vector<int>{1, 2, 2, 3, 5, 6};
  s.merge(nums1, 3, nums2, 3);
  EXPECT_EQ(nums1, res);
}

TEST(merge, merge2) {
  Solution s;
  auto nums1 = std::vector<int>{1};
  auto nums2 = std::vector<int>{};
  auto res = std::vector<int>{1};
  s.merge(nums1, 1, nums2, 0);
  EXPECT_EQ(nums1, res);
}
TEST(merge, merge3) {
  Solution s;
  auto nums1 = std::vector<int>{0};
  auto nums2 = std::vector<int>{1};
  auto res = std::vector<int>{1};
  s.merge(nums1, 0, nums2, 1);
  EXPECT_EQ(nums1, res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}