#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> prices(n), pages(n);
  for (auto &price : prices)
    cin >> price;
  for (auto &page : pages)
    cin >> page;

  vector<ll> prev(x + 1, 0);
  for (int i = 0; i < n; i++) {
    vector<ll> dp(x + 1, 0);
    for (int j = 0; j <= x; j++) {
      dp[j] = prev[j];
      if (j - prices[i] >= 0) {
        dp[j] = max(dp[j], prev[j - prices[i]] + pages[i]);
      }
    }
    prev = dp;
  }

  cout << prev[x] << "\n";

  return 0;
}
