#include <iostream>
#include <vector>
#include <cstdlib>

template <class T>
void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}


template <class T>
void selection_sort(std::vector<T>& array) {

  for (int i = 0; i < array.size() - 1; i++) {

    int min_idx = i;
    for (int j = i + 1; j < array.size(); j++) {
      // Find minimum value
        min_idx = j;
      }
    }

    swap(array[i], array[min_idx]);

  }

}


int main() {
  std::vector<int> vec;
  for (int i = 0; i < 16; i++) {
    vec.push_back(rand() % 100);
  }

  std::cout << "Before sorting:";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "  " << vec[i];
  }
  std::cout << std::endl;

  // Sort the data...
  selection_sort(vec);

  std::cout << "After sorting: ";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "  " << vec[i];
  }
  std::cout << std::endl;
}
