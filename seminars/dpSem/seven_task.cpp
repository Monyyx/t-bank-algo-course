#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll minOperations(ll n) {
  if (n == 1) return 0;

  vector<ll> dp(n + 1, 0);
  dp[1] = 0;

  for (ll i = 2; i <= n; ++i){
    ll minOper = dp[i - 1] + 1;
    if (i % 2 == 0) {
      minOper = min(minOper, dp[i / 2] + 1);
    }
    if (i % 3 == 0) {
      minOper = min(minOper, dp[i / 3] + 1);
    }
    dp[i] = minOper;
  }

    return dp[n];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << minOperations(3) << '\n';  // 1
  cout << minOperations(5) << '\n';  // 3
  cout << minOperations(10) << '\n'; // 3
  cout << minOperations(17) << '\n'; // 5

  return 0;
}