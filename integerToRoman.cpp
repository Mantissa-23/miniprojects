#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string ans = "";
    while(num > 0) {
      if(num / 1000 > 0) {
        ans += "M";
        num -= 1000;
      }
      else if(num / 900 > 0) {
        ans += "CM";
        num -= 900;
      }
      else if(num / 500 > 0) {
        ans += "D";
        num -= 500;
      }
      else if(num / 400 > 0) {
        ans += "CD";
        num -= 400;
      }
      else if(num / 100 > 0) {
        ans += "C";
        num -= 100;
      }
      else if(num / 90 > 0) {
        ans += "XC";
        num -= 90;
      }
      else if(num / 50 > 0) {
        ans += "L";
        num -= 50;
      }
      else if(num / 40 > 0) {
        ans += "XL";
        num -= 40;
      }
      else if(num / 10 > 0) {
        ans += "X";
        num -= 10;
      }
      else if(num / 9 > 0) {
        ans += "IX";
        num -= 9;
      }
      else if(num / 5 > 0) {
        ans += "V";
        num -= 5;
      }
      else if(num / 4 > 0) {
        ans += "IV";
        num -= 4;
      }
      else if(num / 1 > 0) {
        ans += "I";
        num -= 1;
      }
    }
    return ans;
  }
};

TEST_CASE("Tests") {
  Solution s;

  CHECK(s.intToRoman(3) == "III");
  CHECK(s.intToRoman(4) == "IV");
  CHECK(s.intToRoman(9) == "IX");
  CHECK(s.intToRoman(58) == "LVIII");
  CHECK(s.intToRoman(1994) == "MCMXCIV");
  CHECK(s.intToRoman(1) == "I");
}
