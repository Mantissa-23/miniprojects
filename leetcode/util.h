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

bool isEqual(vector<int> arr1, vector<int> arr2) {
  if(arr1.size() != arr2.size())
    return false;

  for(int i = 0; i < arr1.size(); i++) {
    if(arr1[i] != arr2[i])
      return false;
  }
  return true;
}
