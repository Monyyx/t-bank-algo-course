#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll minTime(ll n, vector<ll>& a, vector<ll>& b) {
  vector<ll> dp(n + 2, 0);

  dp[n] = a[n - 1];

  for (ll i = n - 1; i >= 1; --i) {
    ll oneTicket = a[i - 1] + dp[i + 1];

    ll twoTickets = LLONG_MAX;
    if (i < n) {
      twoTickets = b[i - 1] + dp[i + 2];
    }
    dp[i] = min(oneTicket, twoTickets);
  }

  return dp[1];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n = 3;
  vector<ll> a = {2, 3, 4}; //one ticket
  vector<ll> b = {5, 6, 0}; //two tickets

  ll result = minTime(n, a, b);
  cout << result << '\n';

  return 0;
}