#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, m, q;
vector<vector<ll>> SP;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> q;

  SP.resize(n + 1, vector<ll>(n + 1, LLONG_MAX));
  for (int i = 1; i <= n; i++) {
    SP[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    if (c >= SP[a][b])
      continue;
    SP[a][b] = c;
    SP[b][a] = c;
  }

  for (int i = 1; i <= n; i++) {
    SP[i][i] = 0;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (SP[i][k] != LLONG_MAX && SP[k][j] != LLONG_MAX) {
          SP[i][j] = min(SP[i][k] + SP[k][j], SP[i][j]);
        }
      }
    }
  }

  for (int _ = 0; _ < q; _++) {
    int a, b;
    cin >> a >> b;

    cout << (SP[a][b] == LLONG_MAX ? -1 : SP[a][b]) << "\n";
  }

  return 0;
}
