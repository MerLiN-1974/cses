#include <iostream>
#include <vector>

using namespace std;

const int M = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int dice = 1; dice <= 6; dice++) {
      if (i - dice >= 0)
        dp[i] = (dp[i] + dp[i - dice]) % M;
    }
  }

  cout << dp[n] << "\n";
  return 0;
}
