#include <iostream>

void binary_search(int arr[], int low, int high, int target) {
  bool found = false;
  while (low < high) {
    int mid = high + low / 2;
    if (arr[mid] == target) {
      std::cout << "The number " << target << " is at the index " << mid
                << std::endl;
      found = true;
      break;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else if (arr[mid] > target) {
      high = mid - 1;
    }
  }
  if (!found) {
    std::cout << "number not found" << std::endl;
  }
}

int main() {
  int nums[] = {1, 3, 5, 10, 14, 19, 24, 27, 33, 45};
  int low = 0;
  int high = sizeof(nums) / sizeof(nums[0]);
  srand(time(0));
  int random = rand() % 10;

  int target = nums[random];
  binary_search(nums, low, high, target);
  return 0;
}

