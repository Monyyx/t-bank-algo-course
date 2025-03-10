#include <iostream>
#include <vector>
using namespace std;

bool hasSubarrayWithSum(vector<int>& a, int S) {
  int left = 0, sum = 0;

  for (int right = 0; right < a.size(); ++right) {
    sum += a[right];

    while (sum > S) {
      sum -= a[left];
      left++;
    }

    if (sum == S) return true; 
  }

  return false;
}

int main() {
  int n, S;
  cin >> n >> S;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  cout << (hasSubarrayWithSum(a, S) ? "yes" : "no") << '\n';
}
