#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if(numRows < 2)
      return s;
    int n = s.length();
    string ret = "";
    // i is row
    for(int i = 0; i < numRows; i++) {
      for(int j = i; j < n; j += numRows * 2 - 2) {
        ret += s[j];
        if(i != 0 && i != numRows - 1 && j + (numRows - i - 1)*2 < n) {
          ret += s[j + (numRows - i - 1)*2];
        }
      }
    }
    return ret;
  }
};

TEST_CASE("tests") {
  Solution s;

  CHECK(s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
  CHECK(s.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
  CHECK(s.convert("A", 1) == "A");
  CHECK(s.convert("ASDF", 1) == "ASDF");
  CHECK(s.convert("ASDF", 2) == "ADSF");
  CHECK(s.convert("ASDF", 3) == "ASFD");
}
