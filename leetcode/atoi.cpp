#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
      bool negate = false;
      int stage = 0;
      int ans = 0;
      for(int c = 0; c < str.length(); c++) {
        if(stage == 0) {
          if(c == ' ')
            continue;
          else if(c == '-') {
            negate = true;
            stage = 1;
            continue;
          }
          else if(c <= '9' && c >= '0') {
            stage = 1;
          }
          else
            return 0;
        }
        if(stage == 1) {
          if(c <= '9' && c >= '0') {
            ans += c - '0';
            ans *= 10;
          }
          else
            return ans;
        }
      }
    }
};

TEST_CASE("tests") {
  Solution s;
}
