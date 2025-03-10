#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

/*
1 string size
2 nums
3 count oper
other - oper 1 - summ, 2 - xor
*/

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll size, count, oper, left, right;
  cin >> size;
  vector<ll> nums(size);
  vector<ll> prefix(size + 1);
  vector<ll> prefXor(size + 1);
  prefix[0] = 0;

  for (ll i = 0; i < size; ++i){
    cin >> nums[i];
    prefix[i + 1] = prefix[i] + nums[i];  // range sum = pref[]
    prefXor[i + 1] = prefXor[i] ^ nums[i]; // range xor =  prefXor[r] ^ prefXor[l - 1] если 1 нумерация
  }

  cin >> count;
  for ( ; count; --count){
    cin >> oper >> left >> right;
    if (oper == 1){
      cout << prefix[right] - prefix[left - 1] << '\n';
    } else {
      ll temp = prefXor[right] ^ prefXor[left - 1];
      cout << temp << '\n';
    }
  }
  

  

  return 0;
}