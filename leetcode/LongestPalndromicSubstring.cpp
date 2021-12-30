#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    if(s.length() < 2)
      return s;

    int spacing = 0;

    unordered_set<int> valid_even_pivots;
    unordered_set<int> valid_odd_pivots;
    for(int i = 0; i < s.length() - 1; i++) {
      if(s[i] == s[i + 1])
        valid_even_pivots.insert(i);
      if(s[i] == s[i + 2] && i + 2 < s.length())
        valid_odd_pivots.insert(i + 1);
    }

    while(!valid_even_pivots.empty() or !valid_odd_pivots.empty()) {
      auto et = valid_even_pivots.begin();
      while(et != valid_even_pivots.end()) {
        bool valid = s[*et - spacing] == s[*et + 1 + spacing];
        if(!valid) {
          valid_even_pivots.erase(et);
        }
        else {
          et++;
        }
      }
      auto ot = valid_odd_pivots.begin();
      while(ot != valid_odd_pivots.end()) {
        bool valid = s[*ot - 1 - spacing] == s[*ot + 1 + spacing];
        if(!valid) {
          valid_odd_pivots.erase(ot);
        }
        else {
          ot++;
        }
      }
    }
  }

};

TEST_CASE("Tests") {

}
