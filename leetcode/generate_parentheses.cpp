#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include "util.h"
#include "doctest.h"

using namespace std;

class Solution {
public:
  /* vector<string> generateParenthesis(int n) { */
  /*   bool completed = false; */
  /*   vector<vector<string>> configs(n); */
  /*   configs[0] = {"()"}; */
  /*   for(int size = 1; size < n; size++) { */
  /*     configs[size] = vector<string>(); */
  /*     configs[size].push_back("(" + configs[size - 1][0] + ")"); */
  /*     for(int divier = ) */
  /*   } */
  /* } */
  vector<string> answers;
  vector<string> generateParenthesis(int n) {
    _generateParenthesis(n, 1, "(");
    return answers;
  }
  void _generateParenthesis(int n, int depth, string base) {
    if(n > 1)
      _generateParenthesis(n - 1, depth + 1, base + "(");
    if(depth > 0)
      _generateParenthesis(n, depth - 1, base + ")");
    if(depth == 0 && n == 1) {
      answers.push_back(base);
    }
  }
};


TEST_CASE("tests") {
  Solution s;

  int input;
  int soln;

  SUBCASE("1") {
    input = 1;
    soln = 1;
  }
  SUBCASE("2") {
    input = 2;
    soln = 2;
  }
  SUBCASE("3") {
    input = 3;
    soln = 5;
  }
  SUBCASE("4") {
    input = 4;
    soln = 14;
  }

  vector<string> output;
  output = s.generateParenthesis(input);
  print_vector(output);

  bool valid = true;
  for(string s : output) {
    int depth = 0;
    for(char c : s) {
      if(c == '(')
        depth += 1;
      if(c == ')')
        depth -= 1;
      if(depth < 0)
        valid = false;
    }
    if(depth != 0)
      valid = false;
  }
  CHECK(valid);
  CHECK(output.size() == soln);;
}
