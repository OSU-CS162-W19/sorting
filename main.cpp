#include <iostream>
#include <vector>
#include <cstdlib>

int factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n-1);
}

int fibonacci(int n) {
  if (n <= 1) {
    return 1;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}

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
      if (array[j] < array[min_idx]) {
        min_idx = j;
      }
    }

    swap(array[i], array[min_idx]);

  }

}

template <class T>
void insertion_sort(std::vector<T>& array) {
  for (int i = 1; i < array.size(); i++) {
    int j = i;
    while (j > 0 && array[j] < array[j-1]) {
      swap(array[j], array[j-1]);
      j--;
    }
  }
}

template <class T>
int partition(std::vector<T>& array, int lo, int hi) {
  T pivot = array[lo];
  while (true) {
    while (array[lo] < pivot) {
      lo++;
    }
    while (array[hi] > pivot) {
      hi--;
    }
    if (lo >= hi) {
      return hi;
    }
    swap(array[lo], array[hi]);
  }
}


template <class T>
void quicksort_recursive(std::vector<T>& array, int lo, int hi) {
  if (lo < hi) {
    int p = partition(array, lo, hi);
    quicksort_recursive(array, lo, p-1);
    quicksort_recursive(array, p+1, hi);
  }
}


template <class T>
void quicksort(std::vector<T>& array) {
  quicksort_recursive(array, 0, array.size() - 1);
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
  // selection_sort(vec);
  // insertion_sort(vec);
  quicksort(vec);

  std::cout << "After sorting: ";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "  " << vec[i];
  }
  std::cout << std::endl;
}
