#include <iostream>
#include <vector>
#define ll long long
#define ld long double
#define vector std::vector
#define string std::string

int findingNum(vector<ll> in, ll num) {
  ll left = 0;
  ll right = in.size() - 1;
  ll  closest = -1000000000000;
  
  while (left <= right) {
    ll mid = left + (right - left) / 2;
    if (in[mid] == num) {
        return num;
    } else if (in[mid] > num) {
      right = mid - 1;
      if (std::abs(in[mid] - num) < std::abs(closest - num))  closest  = in[mid];
    } else {
      left = mid + 1;
      if (std::abs(in[mid] - num) < std::abs(closest - num))  closest  = in[mid];
    }
  }

  return closest;
}


int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll n, k;
  std::cin >> n >> k;
  vector<ll> in(n); //  up sort
  vector<ll> find(k);

  for (ll i = 0; i < n; ++i) {
    std::cin >> in[i];
  }

  for (ll i = 0; i < k; ++i) {
    std::cin >> find[i];
  }

  for (ll i = 0; i < k; ++i) {
    std::cout << findingNum(in, find[i]) << '\n';
  }
  
}
