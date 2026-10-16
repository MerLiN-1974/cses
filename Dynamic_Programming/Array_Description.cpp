#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

static const char _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

ll M = 1e9 + 7;

int main(void) {
  ll n, m;
  cin >> n >> m;

  vector<ll> arr(n);
  for (ll &x : arr)
    cin >> x;

  vector<ll> prev(m + 2);
  if (arr[0] == 0) {
    for (int j = 1; j <= m; j++)
      prev[j] = 1;
  } else {
    prev[arr[0]] = 1;
  }
  for (int i = 1; i < n; i++) {
    vector<ll> dp(m + 2);
    if (arr[i] == 0) {
      for (int j = 1; j <= m; j++)
        dp[j] = (prev[j - 1] + prev[j] + prev[j + 1]) % M;
    } else {
      dp[arr[i]] = (prev[arr[i] - 1] + prev[arr[i]] + prev[arr[i] + 1]) % M;
    }
    prev = dp;
  }

  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = (ans + prev[i]) % M;
  }

  cout << ans << "\n";

  return 0;
}
