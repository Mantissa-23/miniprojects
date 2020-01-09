#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include "doctest.h"
#include "util.h"

using namespace std;

class Solution {
public:
  bool isOneBitCharacter(vector<int>& bits) {
    if(bits.size() < 2) {
      return !bits[0];
    }
    if(bits[bits.size() - 2] == 0)
      return true;
    else {
      int i = 0;
      while(i < bits.size() - 1) {
        if(bits[i] == 0)
          i++;
        else {
          i += 2;
        }
      }
      if(i == bits.size() - 1)
        return true;
    }
    return false;
  }
};

TEST_CASE("tests") {
  Solution s;

  vector<int> input;
  bool soln;

  SUBCASE("1") {
    input = {1, 0, 0};
    soln = true;
  }
  SUBCASE("2") {
    input = {1, 1, 1, 0};
    soln = false;
  }
  SUBCASE("3") {
    input = {0, 1, 0};
    soln = false;
  }
  SUBCASE("4") {
    input = {0, 1, 0, 0};
    soln = true;
  }
  SUBCASE("5") {
    input = {1, 1, 0};
    soln = true;
  }
  SUBCASE("6") {
    input = {1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0};
    soln = false;
  }

  print_vector(input);
  CHECK(s.isOneBitCharacter(input) == soln);
}
