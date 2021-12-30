#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int maxlength = 0;
      unordered_map<char, int> cur_substring;

      for(int i = 0, j = 0; j < s.length(); j++) {
        if (cur_substring.find(s[j]) != cur_substring.end()) {
          i = max(cur_substring[s[j]], i);
        }
        maxlength = max(maxlength, j - i + 1);
        cur_substring[s[j]] = j + 1;
      }

      return maxlength;
    }
};

TEST_CASE("solution") {
  Solution s;

  CHECK(s.lengthOfLongestSubstring("abcabcbb") == 3);
  CHECK(s.lengthOfLongestSubstring("bbbbb") == 1);
  CHECK(s.lengthOfLongestSubstring("pwwkew") == 3);
  CHECK(s.lengthOfLongestSubstring(" ") == 1);
  CHECK(s.lengthOfLongestSubstring("") == 0);
  CHECK(s.lengthOfLongestSubstring("iiiiiiiwwwwaaawa") == 2);
  CHECK(s.lengthOfLongestSubstring("a") == 1);
  CHECK(s.lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyz") == 26);
  CHECK(s.lengthOfLongestSubstring("dvdf") == 3);
}
