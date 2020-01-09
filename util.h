#include <vector>
#include <iostream>
#include <algorithm> // For copy
#include <iterator>

using namespace std;

template<typename T>
void print_vector(vector<T>& vec) {
  cout << '[';
  copy(vec.begin(), vec.end(), ostream_iterator<T>(std::cout, ", "));
  cout << ']' << endl;
}

