#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include <math.h>
#include "doctest.h"

using namespace std;

class Solution {
public:
  // Brute force soln
  /* int maxArea(vector<int>& height) { */
  /*   int area_max = 0; */
  /*   for(int i = 0; i < height.size(); i++) { */
  /*     for(int j = 0; j < height.size(); j++) { */
  /*       int area_cur = area(height, i, j); */
  /*       if(area_cur > area_max) { */
  /*         area_max = area_cur; */
  /*       } */
  /*     } */
  /*   } */
  /*   return area_max; */
  /* } */
  // Using a "convex hull" approach
  int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int max_area = 0;

    while(i < j) {
      max_area = max(area(height, i, j), max_area);
      if(height[i] < height[j]) {
        i++;
      }
      else {
        j--;
      }
    }
    return max_area;
  }
  int area(vector<int>& height, int i, int j) {
    return abs(j - i) * min(height[i], height[j]);
  }
};


TEST_CASE("tests") {
  Solution s;

  vector<int> height;
  int soln;

  SUBCASE("1") {
    height = {1,8,6,2,5,4,8,3,7};
    soln = 49;
  }
  SUBCASE("Basic Case 1") {
    height = {1, 1};
    soln = 1;
  }
  SUBCASE("Basic Case 2") {
    height = {2, 1, 2};
    soln = 4;
  }
  SUBCASE("Basic Case 3") {
    height = {15, 1, 27};
    soln = 30;
  }

  CHECK(s.maxArea(height) == soln);
}
