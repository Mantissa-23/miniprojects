#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include <iostream>
/* #include <algorithm> // For copy */
/* #include <iterator> */
#include "doctest.h"

using namespace std;

void print_vector(vector<int>& vec);

/* class Solution { */
/* public: */
/*   int find_area_between_maxima(vector<int>& height, vector<int>& maxima, int left, int right) { */
/*     if(maxima.size() < 2 || maxima[right] - maxima[left] < 2) { */
/*       return 0; */
/*     } */

/*     int min_maximum = min(height[maxima[left]], height[maxima[right]]); */
/*     for(int i = left + 1; i < right; i++) { */
/*       if(height[maxima[i]] >= min_maximum) { */
/*         return find_area_between_maxima(height, maxima, left, i) + find_area_between_maxima(height, maxima, i, right); */
/*       } */
/*     } */

/*     int water = 0; */
/*     for(int i = maxima[left]; i < maxima[right]; i++) { */
/*       water += max(0, min_maximum - height[i]); */
/*     } */
/*     return water; */
/*   } */

/*   int trap(vector<int>& height) { */
/*     if(height.size() < 3) { */
/*       return 0; */
/*     } */
/*     // Find minima and maxima */
/*     vector<int> maxima; */
/*     if(height[0] > height[1]) */
/*       maxima.push_back(0); */
/*     for(int i = 1; i < height.size() - 1; i++) { */
/*       if(height[i - 1] <= height[i] && height[i + 1] <= height[i]) { */
/*         maxima.push_back(i); */
/*       } */
/*     } */
/*     if(height[height.size() - 1] > height[height.size() - 2]) */
/*       maxima.push_back(height.size() - 1);; */

/*     /1* print_vector(maxima); *1/ */
/*     return find_area_between_maxima(height, maxima, 0, maxima.size() - 1); */
/*   } */

/* }; */

class Solution {
  public:
    int trap(vector<int>& height) {
      int left = 0;
      int right = height.size() - 1;
      int max_left = 0;
      int max_right = 0;
      int area = 0;
      while(left < right) {
        if(height[left] < height[right]) {
          if(height[left] < max_left) {
            area += max_left - height[left];
          }
          else {
            max_left = height[left];
          }
          left++;
        }
        else {
          if(height[right] < max_right) {
            area += max_right - height[right];
          }
          else {
            max_right = height[right];
          }
          right--;
        }
      }
      return area;
    }
};

/* void print_vector(vector<int>& vec) { */
/*   cout << '['; */
/*   copy(vec.begin(), vec.end(), ostream_iterator<int>(std::cout, ", ")); */
/*   cout << ']' << endl; */
/* } */

TEST_CASE("tests") {
  Solution s;
  
  vector<int> height;
  int soln;

  SUBCASE("1") {
    height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    soln = 6;
  }
  SUBCASE("2") {
    height = {6, 0, 5, 0, 4, 0, 3, 0, 2, 0, 1};
    soln = 15;
  }
  SUBCASE("3") {
    height = {10, 0, 0, 10};
    soln = 20;
  }
  SUBCASE("4") {
    height = {5, 4, 1, 2};
    soln = 1;
  }
  SUBCASE("5") {
    height = {1, 2, 3, 4, 3, 2, 1};
    soln = 0;
  }
  SUBCASE("6") {
    height = {1, 1};
    soln = 0;
  }
  SUBCASE("7") {
    height = {2, 1, 2};
    soln = 1;
  }
  SUBCASE("8") {
    height = {1, 2, 3, 4, 3, 2, 3, 4, 3, 2, 1};
    soln = 4;
  }
  SUBCASE("9") {
    height = {1, 2, 3, 4, 3, 0, 3, 4, 3, 2, 1};
    soln = 6;
  }
  SUBCASE("10") {
    height = {5, 2, 1, 2, 1, 5};
    soln = 14;
  }
  SUBCASE("11") {
    height = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
    soln = 23;
  }

  CHECK(s.trap(height) == soln);
}
