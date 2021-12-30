#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <unordered_set>
#include "doctest.h"

using namespace std;

// Hashset
/* class Solution { */
/* public: */
/*     int singleNumber(vector<int>& nums) { */
/*         unordered_set<int> s; */
        
/*         for(int i = 0; i < nums.size(); i++) { */
/*             if(s.find(nums[i]) == s.end()) */
/*                 s.insert(nums[i]); */
/*             else */
/*                 s.erase(nums[i]); */
/*         } */
        
/*         return *s.begin(); */
/*     } */
/* }; */

// Abusing xor
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        
        for(int i = 0; i < nums.size(); i++) {
          a ^= nums[i];
        }
        
        return a;
    }
};

TEST_CASE("tests") {
  Solution s;

  vector<int> t;
  int ans;

  SUBCASE("1") {
    t = {2,2,1};
    ans = 1;
  }
  SUBCASE("2") {
    t = {4,1,2,1,2};
    ans = 4;
  }
  
  CHECK(s.singleNumber(t) == ans);
}
