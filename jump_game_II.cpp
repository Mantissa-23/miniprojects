#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include <limits>
#include <iostream>
#include <unordered_set>
#include "doctest.h"

using namespace std;

// n^2 solution
/* class Solution { */
/* public: */
/*   int jump(vector<int>& nums) { */
/*     int n = nums.size(); */
/*     int dp[n]; */

/*     for(int i = 0; i < n; i++) */
/*       dp[i] = numeric_limits<int>::max(); */

/*     dp[0] = 0; */

/*     for(int i = 1; i < n; i++) { */
/*       for(int j = 0; j < i; j++) { */
/*         if(i - j <= nums[j]) { */
/*           dp[i] = min(dp[i], dp[j] + 1); */
/*         } */
/*       } */
/*     } */

/*     return dp[n - 1]; */
/*   } */
/* }; */

// ~n solution
class Solution {
public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int dp[n];

    if(n == 1)
      return 0;

    for(int i = 0; i < n; i++)
      dp[i] = numeric_limits<int>::max();

    dp[0] = 0;

    vector<int> stack;
    vector<bool> visited(n, false);

    int last = 0;
    int i = 0;
    visited[0] = true;
    while(i != n - 1) {
      visited[i] = true;
      int far = min(i + nums[i], n - 1);
      for(int j = i + 1; j <= far; j++) {
        dp[j] = min(dp[j], dp[i] + 1);
        if (!visited[j])
          stack.push_back(j);
      }
      last = i;
      i = stack.back();
      stack.pop_back();
    }

    return dp[last] + 1;
  }
};

TEST_CASE("Tests") {
  Solution s;

  vector<int> input;
  int output;

  SUBCASE("1") {
    input = {2,3,1,1,4};
    output = 2;
  }
  SUBCASE("2") {
    input = {1,2};
    output = 1;
  }
  SUBCASE("3") {
    input = {3,7,6,9,1,2,4};
    output = 2;
  }
  SUBCASE("4") {
    input = {2,1,1};
    output = 1;
  }
  SUBCASE("25000") {
    input = {25000, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    output = 1;
  }

  cout << "{";
  for(auto i : input)
    cout << i << ",";
  cout << "}" << endl;
  CHECK(s.jump(input) == output);
}
