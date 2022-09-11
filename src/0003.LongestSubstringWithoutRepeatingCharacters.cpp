#include "headers.h"

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int result = 0;
        std::unordered_map<char, int> lookup;
        for (int left = 0, right = 0; right < s.length(); ++right) {
            if (lookup.count(s[right])) {
                left = std::max(left, lookup[s[right]] + 1);
            }
            lookup[s[right]] = right;
            result = std::max(result, right - left + 1);
        }
        return result;
    }
};

TEST(lengthOfLongestSubstring, LongestSubstringWithoutRepeatingCharacters1) {
    Solution s;
    EXPECT_TRUE(s.lengthOfLongestSubstring("abcdeafbdfcbb") == 7);
}

TEST(lengthOfLongestSubstring, LongestSubstringWithoutRepeatingCharacters2) {
    Solution s;
    EXPECT_TRUE(s.lengthOfLongestSubstring("bbbbb") == 1);
}

TEST(lengthOfLongestSubstring, LongestSubstringWithoutRepeatingCharacters3) {
    Solution s;
    EXPECT_TRUE(s.lengthOfLongestSubstring("a") == 1);
}

TEST(lengthOfLongestSubstring, LongestSubstringWithoutRepeatingCharacters4) {
    Solution s;
    EXPECT_TRUE(s.lengthOfLongestSubstring("au") == 2);
}

TEST(lengthOfLongestSubstring, LongestSubstringWithoutRepeatingCharacters5) {
    Solution s;
    EXPECT_TRUE(s.lengthOfLongestSubstring("bwt") == 3);
}

TEST(lengthOfLongestSubstring, LongestSubstringWithoutRepeatingCharacters6) {
    Solution s;
    EXPECT_TRUE(s.lengthOfLongestSubstring("abba") == 2);
}
