#include <iostream>
#include <vector>

using namespace std;

const int M = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (auto &k : coins)
    cin >> k;

  vector<int> dp(x + 1);
  dp[0] = 1;

  for (auto &coin : coins) {
    for (int i = 1; i <= x; i++) {
      if (i - coin >= 0) {
        dp[i] = (dp[i] + dp[i - coin]) % M;
      }
    }
  }

  cout << dp[x] << "\n";

  return 0;
}
