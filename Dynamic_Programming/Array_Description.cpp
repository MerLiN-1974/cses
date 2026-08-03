#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int M = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;
  vector<ll> arr(n);
  for (auto &x : arr)
    cin >> x;

  vector<ll> prev(m + 2, 0);

  if (arr[0] == 0) {
    for (ll i = 1; i <= m; i++)
      prev[i] = 1;
  } else
    prev[arr[0]] = 1;

  for (ll i = 1; i < n; i++) {
    vector<ll> dp(m + 2, 0);
    if (arr[i] == 0) {
      for (ll j = 1; j <= m; j++)
        dp[j] = (prev[j - 1] + prev[j] + prev[j + 1]) % M;
    } else {
      dp[arr[i]] = (prev[arr[i] - 1] + prev[arr[i]] + prev[arr[i] + 1]) % M;
    }
    prev = dp;
  }

  ll ans = 0;
  for (int i = 1; i <= m; i++)
    ans = (ans + prev[i]) % M;

  cout << ans << "\n";

  return 0;
}
