#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  /*
  ll size, left, right;
  cin >> size;
  vector<ll> nums(size);
  vector<ll> prefix(size + 1);
  prefix[0] = 0;

  for (ll i = 0; i < size; ++i){
    cin >> nums[i];
    prefix[i + 1] = prefix[i] + nums[i];  // range sum = pref[right] - prefix[left - 1]
  }

  cin >> left >> right;
  cout << prefix[right] - prefix[left - 1] << '\n';
  */

  ll size, x1, y1, x2, y2;
  cin >> size;
  vector<vector<ll>> matrix(size, vector<ll>(size));
  vector<vector<ll>> prefix(size + 1, vector<ll>(size + 1, 0));

  for (ll i = 0; i < size; ++i){
    for (ll j = 0; j < size; ++j){
      cin >> matrix[i][j];
    }
  }

  for (ll i = 1; i <= size; ++i){
    for (ll j = 1; j <= size; ++j){
      prefix[i][j] = matrix[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
    }
  }

  cin >> x1 >> y1 >> x2 >> y2;
  ll rangeSum = prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
  cout << rangeSum << '\n';

  return 0;
}