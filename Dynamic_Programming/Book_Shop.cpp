#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> price(n);
  for (auto &p : price)
    cin >> p;
  vector<int> page(n);
  for (auto &p : page)
    cin >> p;

  // NOTE: dp[i][j] = max pages in first i pages with max budget j
  vector<int> prev(x + 1, 0), curr(x + 1, 0);

  for (int i = 1; i <= n; i++) {
    int curr_page = page[i - 1];
    int curr_price = price[i - 1];
    for (int j = 1; j <= x; j++) {
      curr[j] = prev[j];

      if (j - curr_price >= 0) {
        curr[j] = max(curr[j], prev[j - curr_price] + curr_page);
      }
    }

    prev = curr;
  }

  cout << curr[x] << "\n";

  return 0;
}
