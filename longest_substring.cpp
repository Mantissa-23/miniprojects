#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int curlength = 0;
      int maxlength = 0;
      unordered_set<char> cur_substring;

      for(int i = 0; i < s.length(); i++) {
        if(cur_substring.find(s[i]) != cur_substring.end()) {
          maxlength = max(maxlength, curlength);
          curlength = 0;
          cur_substring.clear();
        }
        else {
          curlength++;
          cur_substring.insert(s[i]);
        }
      }

      maxlength = max(maxlength, curlength);

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
