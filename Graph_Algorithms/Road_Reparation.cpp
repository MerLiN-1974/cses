#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <variant>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<ll, int>>> Alist(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    Alist[u].push_back({c, v});
    Alist[v].push_back({c, u});
  }

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq{};
  vector<bool> visited(n + 1);
  pq.push({0, 1});

  ll total = 0;

  while (not pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (visited[u])
      continue;
    total += d;
    visited[u] = true;
    for (auto [w, v] : Alist[u]) {
      if (not visited[v]) {
        pq.push({w, v});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (not visited[i]) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  cout << total << "\n";

  return 0;
}
