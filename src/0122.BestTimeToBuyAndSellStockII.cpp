#include "headers.h"

class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) {
    // проаверяем что входдные данные позволяют делать расчет
    if (prices.empty() || prices.size() <= 1) {
      return 0;
    }

    int totalProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
      // Проверяем, что есть выгода, по сравнению с предыдущим днем
      // Если есть - покупаем вчерашние и продаём сегодня.
      // Складываем полученный профит
      if (prices[i - 1] < prices[i]) {
        totalProfit += prices[i] - prices[i - 1];
      }
    }

    return totalProfit;
  }
};

TEST(maxProfit, maxProfit1) {
  Solution s;
  EXPECT_EQ(s.maxProfit({7, 1, 5, 3, 6, 4}), 7);
}

TEST(maxProfit, maxProfit2) {
  Solution s;
  EXPECT_EQ(s.maxProfit({1, 2, 3, 4, 5}), 4);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
