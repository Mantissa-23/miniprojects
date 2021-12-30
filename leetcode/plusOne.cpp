
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> ret;
    bool inc = false;
    for(auto it = digits.rbegin(); it < digits.rend(); it++) {
      if(it == digits.rbegin())
        ret.push_back((*it + 1) % 10);
      if((*it + 1) > 9)
        inc = true;
    }
  }
};

TEST_CASE("tests") {
  Solution s;

  vector<int> nums;
  vector<int> soln;

  SUBCASE("0") {

  }

  vector<int> result = s.plusOne(nums);
  CHECK(result == soln);
}
