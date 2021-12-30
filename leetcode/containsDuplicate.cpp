#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <unordered_set>
#include "doctest.h"

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      // Make a set of values
      unordered_set<int> values;
      for(int i = 0; i < nums.size(); i++) {
        // If our set already contains a value, we know there are duplicates
        if(values.find(nums[i]) != values.end())
          return true;
        values.insert(nums[i]);
      }
      // otherwise there can't be any duplicates
      return false;
    }
};

TEST_CASE("tests") {
  Solution s;

  vector<int> nums;
  bool soln;

  SUBCASE("0") {
    nums = {};
    soln = false;
  }
  SUBCASE("0") {
    nums = {1};
    soln = false;
  }
  SUBCASE("1") {
    nums = {1, 2, 3, 1};
    soln = true;
  }
  SUBCASE("2") {
    nums = {1, 1, 2, 2, 3, 5, 1, 2, 1, 2};
    soln = true;
  }
  SUBCASE("3") {
    nums = {1};
    soln = false;
  }
  SUBCASE("4") {
    nums = {1, 2, 3, 4};
    soln = false;
  }
  SUBCASE("5") {
    nums = {44, 44, 44, 44, 44};
    soln = true;
  }

  CHECK(s.containsDuplicate(nums) == soln);
}
