#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define ld long double
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll max;
  ll min  = 1;
  ll mid;
  cin >> max;


  while (max > min){
    mid = (min + max + 1) / 2;
    cout << mid  << '\n';
    fflush(stdout);
    string input;
    cin >> input;

    if (input == "<") {
      max = mid - 1;
    } 
    else {
      min = mid;
    }
  }

  cout << "! " << min;
  return 0;
}
/*
20
5 <
3 >=
4 >=
! 4
*/