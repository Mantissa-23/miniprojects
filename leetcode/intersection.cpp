#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <unordered_map>
#include "doctest.h"

using namespace std;

// Using hashmaps
/* class Solution { */
/* public: */
/*     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { */
/*         unordered_map<int, int> set1, set2; */

/*         for(const int& i : nums1) { */
/*           if(set1.find(i) == set1.end()) { */
/*             set1[i] = 1; */
/*           } */
/*           else */
/*             set1[i]++; */
/*         } */
/*         for(const int& i : nums2) { */
/*           if(set1.find(i) != set1.end()) { */
/*             if(set2.find(i) == set2.end()) */
/*               set2[i] = 1; */
/*             else if(set2[i] < set1[i]) */
/*               set2[i]++; */
/*           } */
/*         } */

/*         vector<int> ret; */
/*         for(auto it = set2.begin(); it != set2.end(); it++) { */
/*           for(int i = 0; i < it->second; i++) { */
/*             ret.push_back(it->first); */
/*           } */
/*         } */

/*         return ret; */
/*     } */
/* }; */

class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());
      vector<int> ret;
      for(auto i = nums1.begin(), j = nums2.begin(); i != nums1.end() && j != nums2.end();) {
        if(*i == *j) {
          ret.push_back(*i);
          i++;
          j++;
        }
        else if (*i < *j)
          i++;
        else
          j++;
      }
      return ret;
    }
};

TEST_CASE("tests") {
  Solution s;

  vector<int> arr1;
  vector<int> arr2;
  vector<int> soln;

  SUBCASE("1") {
    arr1 = {1, 2, 2, 1};
    arr2 = {2, 2};
    soln = {2, 2};
  }
  SUBCASE("2") {
    arr1 = {4,9,5};
    arr2 = {9,4,9,8,4};
    soln = {4,9};
  }
  SUBCASE("empties") {
    arr1 = {};
    arr2 = {1,2,3};
    soln = {};
  }
  SUBCASE("empties2") {
    arr1 = {1,2,3};
    arr2 = {};
    soln = {};
  }
  SUBCASE("single_item_nonintersecting") {
    arr1 = {1};
    arr2 = {2};
    soln = {};
  }
  SUBCASE("single_item_intersecting") {
    arr1 = {1};
    arr2 = {1};
    soln = {1};
  }

  CHECK(s.intersect(arr1, arr2) == soln);
}
