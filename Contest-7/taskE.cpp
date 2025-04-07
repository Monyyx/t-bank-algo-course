#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("tune=native")
#pragma GCC target("avx2")

#define ll long long
#define ld long double
#define str string
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define vstr vector<str>
#define vpll vector<pll>
#define pb push_back

constexpr ll mod = 1e9 + 7;
constexpr ll mod2 = 1e9 + 9;
constexpr ll pInf = std::numeric_limits<ll>::max();
constexpr ll mInf = std::numeric_limits<ll>::min();
const ll base = 31;
const ll base1 = 67, base2 = 71;


ll distance(str S, str T) {
    ll M = S.length();
    ll N = T.length();

    if (M == 0) return N;
    if (N == 0) return M;

    const ll INF = M + N + 1;
    vector<vll> D(M + 2, vll(N + 2, INF));

    for (ll i = 0; i <= M; ++i) {
        D[i + 1][1] = i;
        D[i + 1][0] = INF;
    }
    for (ll j = 0; j <= N; ++j) {
        D[1][j + 1] = j;
        D[0][j + 1] = INF;
    }

    unordered_map<char, ll> lastPosition;
    for (auto c = 'A'; c <= 'Z'; ++c) {
        lastPosition[c] = 0;
    }

    for (ll i = 1; i <= M; ++i) {
        ll last = 0;
        for (ll j = 1; j <= N; ++j) {
            ll i_prime = lastPosition[T[j - 1]]; // last ppos T[j-1] в S
            ll j_prime = last;                   // last pos S[i-1] в T

            if (S[i - 1] == T[j - 1]) {
                D[i + 1][j + 1] = D[i][j];
                last = j;
            } else {
                // min cost
                D[i + 1][j + 1] = std::min({
                                                   D[i][j] + 1,      // change
                                                   D[i + 1][j] + 1,  // add
                                                   D[i][j + 1] + 1   // delete
                                           });
            }

            if (i_prime > 0 && j_prime > 0 && S[i_prime - 1] == T[j - 1] && S[i - 1] == T[j_prime - 1]) {
                ll transposeCost = D[i_prime][j_prime] + (i - i_prime - 1) + 1 + (j - j_prime - 1);
                D[i + 1][j + 1] = std::min(D[i + 1][j + 1], transposeCost);
            }
        }
        lastPosition[S[i - 1]] = i;
    }

    return D[M + 1][N + 1];
}

int main() {
    str S, T;
        cin >> S >> T;

    cout << distance(S, "") << '\n';
    return 0;
}