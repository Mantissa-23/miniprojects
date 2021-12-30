#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "util.h"

using namespace std;

class Solution {
public:
  // All we care about is local minima and maxima. The maximum profit that
  // we can make consists of the difference between the high points and their
  // corresponding low points on the left.
  int maxProfit(vector<int> &prices) {
    int accum = 0;
    for(int i = 1; i < prices.size(); i++) {
      if(prices[i] > prices[i - 1]) {
        accum += prices[i] - prices[i - 1];
      }
    }
    return accum;
  }
};

TEST_CASE("tests") {
  Solution s;

  vector<int> arr;
  int soln;
  
  SUBCASE("0") {
    arr = {};
    soln = 0;
  }
  SUBCASE("0") {
    arr = {1};
    soln = 0;
  }
  SUBCASE("1") {
    arr = {7, 1, 5, 3, 6, 4};
    soln = 7;
  }
  SUBCASE("2") {
    arr = {1,2,3,4,5};
    soln = 4;
  }
  SUBCASE("3") {
    arr = {7,6,4,3,1};
    soln = 0;
  }
  SUBCASE("4") {
    arr = {5,0,1,1,1,1,1,1,21,22,21};
    soln = 22;
  }
  SUBCASE("5") {
    arr = {0,1,0,1,0,1,0,1,0,1};
    soln = 5;
  }
  SUBCASE("6") {
    arr = {0, 7, 0};
    soln = 7;
  }

  CHECK(s.maxProfit(arr) == soln);
}
