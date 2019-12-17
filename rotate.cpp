#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include "doctest.h"

using namespace std;

// Out-of-place
/* class Solution { */
/* public: */
/*     void rotate(vector<int>& nums, int k) { */
/*       int shift = k % nums.size(); */

/*       vector<int> ret(nums.size()); */

/*       for(int i = 0; i < nums.size(); i++) { */
/*         int slot = (i + k) % nums.size(); */
/*         ret[slot] = nums[i]; */
/*       } */

/*       nums = ret; */
/*     } */
/* }; */

// Out-of-place without modulo at every iteration
/* class Solution { */
/* public: */
/*     void rotate(vector<int>& nums, int k) { */
/*       int n = nums.size(); */
/*       if(n == 0 || k == 0) */
/*         return; */

/*       int shift = k % n; */
/*       if(shift < 0) */
/*         shift = n + shift; */

/*       vector<int> ret(n); */

/*       int i = 0; */
/*       for(int j = n - k; j < n; j++) { */
/*         ret[i] = nums[j]; */
/*         i++; */
/*       } */
/*       for(int j = 0; j < n - k; j++) { */
/*         ret[i] = nums[j]; */
/*         i++; */
/*       } */

/*       nums = ret; */
/*     } */
/* }; */

// In-place solution
class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      int shift = n - k;
      shift = shift % n;

      reverse(nums.begin(), nums.begin() + shift);
      reverse(nums.begin() + shift, nums.begin() + n);
      reverse(nums.begin(), nums.end());
    }
};

TEST_CASE("tests") {
  Solution s;

  vector<int> input;
  int k;
  vector<int> output;

  SUBCASE("1") {
    input = {1,2,3,4,5,6,7};
    k = 3;
    output = {5,6,7,1,2,3,4};
  }
  SUBCASE("2") {
    input = {-1, -100, 3, 99};
    k = 2;
    output = {3, 99, -1, -100};
  }

  s.rotate(input, k);
  CHECK(input == output);
}
