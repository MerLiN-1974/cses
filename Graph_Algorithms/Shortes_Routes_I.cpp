#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
vector<ll> dist;
vector<vector<pair<ll, int>>> Alist;
vector<bool> visited;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  Alist.resize(n + 1);
  visited.resize(n + 1, false);
  dist.resize(n + 1, LLONG_MAX);

  for (int i = 0; i < m; i++) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    Alist[u].push_back(make_pair(c, v));
  }

  dist[1] = 0;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq{};
  pq.push({0, 1});

  while (not pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (visited[u])
      continue;
    visited[u] = true;

    for (auto [w, v] : Alist[u]) {
      if (visited[v])
        continue;

      if (d + w < dist[v]) {
        dist[v] = d + w;
        pq.push({dist[v], v});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }
  cout << "\n";

  return 0;
}
