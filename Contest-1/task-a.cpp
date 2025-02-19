#include <iostream>
#include <vector>
#define ll long long
#define ld long double
#define vector std::vector
#define string std::string

/*
В первой строке содержатся числа n и k (1 6 n, k 6 105
).
Во второй строке задаются n элементов первого массива, отсортированного по возрастанию, а в
третьей строке — k вопросов. Все элементы целые, в диапазоне [−109
; 109
].
Формат выходных данных
Для каждого из k чисел второго массива выведите в отдельную строку «YES», если это число
встречается в первом массиве, и «NO» в противном случае. */

string binSearch(vector<ll> input, ll num){
  ll left  = input.size();
  ll right = 0;
  ll mid = (left + right) / 2;

  while (std::abs(right - left) > 1){
    if (input[mid] == num) {
      return "YES";
    } else if (input[mid] > num){
      left = mid;
      mid = (left + right) / 2;
    } else if (input[mid] < num){
      right = mid;
      mid = (right + left) / 2;
    }
  }

  return "NO";
}


int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll n,k;
  std::cin >> n >> k;
  vector<ll> input(k);
  vector<ll> find(n);

  for (int i = k; i > 0; --i ){
    std::cin >> input[i];
  }

  for (int i = n; i > 0; --i) {
    std::cin >> find[i];
  }

  for (int i = k; i > 0; --i ){
    std::cout << binSearch(input, find[i]) << '\n';
  }

  


}