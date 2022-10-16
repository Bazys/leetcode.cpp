#include "headers.h"

class Solution {
 public:
  std::string addBinary(std::string a, std::string b) {
    std::string s = "";
    int carry{0}, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry == 1) {
      carry += i >= 0 ? a[i--] - '0' : 0;
      carry += j >= 0 ? b[j--] - '0' : 0;
      s = char(carry % 2 + '0') + s;
      carry /= 2;
    }
    return s;
  }
};

TEST(addBinary, addBinary1) {
  Solution s;
  EXPECT_EQ(s.addBinary("1010", "1011"), "10101");
}

TEST(addBinary, addBinary2) {
  Solution s;
  EXPECT_EQ(s.addBinary("11", "1"), "100");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}