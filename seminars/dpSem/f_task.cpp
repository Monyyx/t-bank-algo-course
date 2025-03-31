#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll findWays_2(ll n) // like fibb nums
{
  if (n < 1) return 0;
  if (n == 1) return 1;

  vector<ll> dp(n + 1, 0);
  dp[1] = 1;
  dp[2] = 2;

  for (ll i = 3; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

ll findWay(ll n, ll k)
{
  if (n < 1) return 0;
  if (n == 1) return 1;

  vector<ll> dp(n + 1, 0);
  dp[1] = 1;

  for (ll i = 2; i <= n; ++i) {
    for (ll j = 1; j <= min(k, i - 1); ++j) {
      dp[i] += dp[i - j];
    }
  }

  return dp[n];
}

long long fast(ll n, ll k) {
  if (n < 1) return 0;
  if (n == 1) return 1;

  vector<ll> dp(n + 1, 0);
  dp[1] = 1;
  ll S = 1;  // sum in window

  // i <= k + 1
  for (int i = 2; i <= std::min(n, k + 1); ++i) {
    for (int j = 1; j <= i - 1; ++j) {
      dp[i] += dp[i - j];
    }
    S = dp[i];
  }

  //  i > k + 1
  for (int i = k + 2; i <= n; ++i) {
    S = S + dp[i - 1] - dp[i - k - 1];  // add new - old
    dp[i] = S;
  }

  return dp[n];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << findWays_2(1) << '\n';
  cout << findWay(5, 15) << '\n';
  cout << fast(5,15) << '\n';

  return 0;
}