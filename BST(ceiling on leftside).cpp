#include <iostream>
#include <set>

int main() {
  std::set<int> mySet = {2, 5, 8, 12, 15};
  int target = 7;

  // Find the ceiling of target in mySet
  auto it = mySet.lower_bound(target);

  // If the iterator is valid, it points to the ceiling element
  if (it != mySet.end()) {
    std::cout << "Ceiling of " << target << " is: " << *it << std::endl;
  } else {
    std::cout << "No ceiling found for " << target << std::endl;
  }

  return 0;
}