#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

// Naive implementation
/* string fizzbuzz(int x) { */
/*   string str = ""; */
/*   if(x % 3 == 0) */
/*     str += "Fizz"; */
/*   if(x % 5 == 0) */
/*     str += "Buzz"; */
/*   if(x % 3 != 0 && x % 5 != 0) */
/*     str += to_string(x); */
/*   return str; */
/* } */

/**
 * Holds a FizzBuzz filter; a filter takes an int and returns a string.
 */
template<typename T>
struct FizzBuzzFilter {
  bool exclusive; ///< An exclusive FizzBuzz filter will eliminate any current and future output from other FizzBuzzFilters and only the exclusive filter will be applied.
  function<string(T)> filter; ///< Outputs arbitrary strings based on integer input. See fizzbuzz(int x) for default implementation and example.
  FizzBuzzFilter(function<string(T)> _filter, bool _exclusive=false) : exclusive(_exclusive), filter(_filter) {};
  FizzBuzzFilter() : exclusive(false), filter([] (T x) {return "";}) {};
};

/**
 * fizzbuzz applies all filters sequentially; if no filters match, default_filter will be applied.
 *
 * @param x The value to be filtered.
 * @param filters Each filter will be applied sequentially, one after another, 
 * the result of each being concatenated unless a filter is exclusive; the 
 * first exclusive filter that returns a non-empty string will take over 
 * output, erasing past output and ignoring future output.
 * @param default_filter If no filters were successfully applied (all filters 
 * returned a blank string), this filter will be applied.
 */
template<typename T>
string fizzbuzz(T x, vector<FizzBuzzFilter<T>> filters, FizzBuzzFilter<T> default_filter=FizzBuzzFilter<T>()) {
  string str = "";
  for(auto i : filters) {
    if(i.exclusive) {
      string temp = i.filter(x);
      if(temp != "") {
        str = i.filter(x);
        break;
      }
    }
    else {
      str += i.filter(x);
    }
  }
  if(str == "") {
    str = default_filter.filter(x);
  }
  return str;
}

/**
 * Default implementation of FizzBuzz
 */
string fizzbuzz(int x) {
  return fizzbuzz<int>(x, {
      FizzBuzzFilter<int>([](int x) {return x % 3 == 0 ? "Fizz" : "";}),
      FizzBuzzFilter<int>([](int x) {return x % 5 == 0 ? "Buzz" : "";}),
      }, 
      FizzBuzzFilter<int>([](int x) {return x % 5 != 0 && x % 3 != 0 ? to_string(x) : "";}));
}

int main(int argc, char** argv) {
  for(int i = 1; i <= 100; i++) {
    cout << fizzbuzz(i) << endl;
  }
}

