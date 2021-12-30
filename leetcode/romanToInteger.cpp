#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int singleCharToInt(char c) {
    int val = 0;
    switch(c) {
      case 'I':
        val += 1;
        break;
      case 'V':
        val += 5;
        break;
      case 'X':
        val += 10;
        break;
      case 'L':
        val += 50;
        break;
      case 'C':
        val += 100;
        break;
      case 'D':
        val += 500;
        break;
      case 'M':
        val += 1000;
        break;
    }
    return val;
  }

  int romanToInt(string s) {
    int prevval = 0;
    int val = 0;

    for(int i = 0; i < s.length(); i++) {
      int curval = singleCharToInt(s[i]);
      if((prevval == 1 && (curval == 5 || curval == 10)) ||
          (prevval == 10 && (curval == 50 || curval == 100)) ||
          (prevval == 100 && (curval == 500 || curval == 1000)))
        val -= prevval * 2;
      val += curval;
      prevval = curval;
    }
    return val;
  }
};

TEST_CASE("Tests") {
  Solution s;

  CHECK(s.romanToInt("III") == 3);
  CHECK(s.romanToInt("IV") == 4);
  CHECK(s.romanToInt("IX") == 9);
  CHECK(s.romanToInt("LVIII") == 58);
  CHECK(s.romanToInt("MCMXCIV") == 1994);

}
