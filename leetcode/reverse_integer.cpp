#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <limits>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int reversed = 0;
    while(x != 0) {
      // This can be done easier by taking numeric_limits<int>::max() / 10 and numeric_limits<int>::min() / 10 and comparing them to reversed
      if((reversed > 0 && numeric_limits<int>::max() / reversed < 10) || (reversed < 0 && numeric_limits<int>::min() / reversed < 10))
        return 0;
      reversed = reversed * 10 + x % 10;
      x /= 10;
    }
    return reversed;
  }
};

TEST_CASE("Tests") {
  Solution s;

  CHECK(s.reverse(123) == 321);
  CHECK(s.reverse(-123) == -321);
  CHECK(s.reverse(120) == 21);
  CHECK(s.reverse(1) == 1);
  CHECK(s.reverse(0) == 0);
  CHECK(s.reverse(32150) == 5123);
  CHECK(s.reverse(1534236469) == 0);
}
