#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        
        int i = 1;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j];
                i++;
            }
        }
        
        return i;
    }
};

template<typename T>
bool isEqual(std::vector<T> const &v1, std::vector<T> const &v2, int len)
{
  for (int i = 0; i < len; i++)
    if(v1[i] != v2[i])
      return false;
  return true;
}

TEST_CASE("solution") {
  Solution s;

  vector<int> t;
  vector<int> tt;
  int expected_len;

  SUBCASE("Short") {
    t = {1,1,2};
    tt = {1, 2};
  }
  SUBCASE("Long") {
    t = {0,0,1,1,1,2,2,3,3,4};
    tt = {0,1,2,3,4};
  }
  SUBCASE("1") {
    t = {0,0,0,3,3,4,4,4,4,4,8,8,10,12,20};
    tt = {0,3,4,8,10,12,20};
  }

  int len = s.removeDuplicates(t);
  CHECK(len == tt.size());
  CHECK(isEqual(t, tt, len));
}
