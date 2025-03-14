#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> events;

  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    events.emplace_back(l, +1);      // старт отрезка
    events.emplace_back(r + 1, -1);  // конец отрезка 
  }

  sort(events.begin(), events.end()); // сортируем события по координатам

  int maxCover = 0, currentCover = 0, bestPoint = 0;

  for (auto [x, type] : events) {
    currentCover += type; // +1 (начало) или -1 (конец)
    if (currentCover > maxCover) { // обновляем максимум и точку
      maxCover = currentCover;
      bestPoint = x;
      }
  }

    cout << bestPoint << '\n';
}
/*
5
1 5
2 6
3 4
7 8
2 3

--3--
*/