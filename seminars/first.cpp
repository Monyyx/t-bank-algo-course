#include <iostream>
#include <vector>
using namespace std;

int findTransitionPoint(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] > arr[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// бин поиск по возрастанию
int binSearchUP(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// бин поиск по убыванию
int binSearchDOWN(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

   // 1. Находим точку перехода
  int pivot = findTransitionPoint(arr);

   // 2. Ищем отдельно в обеих частях
  int result = binSearchUP(arr, 0, pivot, target);
  if (result == -1) {
    result = binSearchDOWN(arr, pivot + 1, n - 1, target);
    }

    cout <<< result << "\n";
    
  return 0;
}
