#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <unordered_map>
#include "doctest.h"
#include "util.h"

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if(nums.size() == 0)
      return 0;

    int i = 0;
    for(int j = 0; j < nums.size(); j++) {
      if(nums[i] != nums[j]) {
        i++;
        nums[i] = nums[j];
      }
    }
    return i + 1;
  }
};

TEST_CASE("tests") {
  Solution s;

  vector<int> arr;
  vector<int> soln;

  SUBCASE("0") {
    arr = {};
    soln = {};
  }
  SUBCASE("1") {
    arr = {1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    soln = {1, 2, 3, 4};
  }
  SUBCASE("2") {
    arr = {0, 0, 0, 1, 1, 2, 3, 3, 3, 4, 4};
    soln = {0, 1, 2, 3, 4};
  }
  SUBCASE("3") {
    arr = {0, 7, 11, 13, 13, 28, 28, 28, 55, 77, 77, 77};
    soln = {0, 7, 11, 13, 28, 55, 77};
  }
  SUBCASE("4") {
    arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    soln = {1};
  }

  CHECK(s.removeDuplicates(arr) == soln.size());
  isEqual(arr, soln);
}
