#include <climits>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, ll>> edges{};

  for (int _ = 0; _ < m; _++) {
    ll u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  vector<ll> dist(n + 1, LLONG_MIN);
  dist[1] = 0;

  // Use bellman Ford
  for (int i = 0; i < n - 1; i++) {
    for (auto &[u, v, w] : edges) {
      if (dist[u] != LLONG_MIN && dist[u] + w > dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }

  // check for positive cycle
  for (int i = 0; i < n; i++) {
    for (auto &[u, v, w] : edges) {
      if (dist[u] != LLONG_MIN) {
        if (dist[u] == LLONG_MAX || dist[u] + w > dist[v]) {
          dist[v] = LLONG_MAX;
        }
      }
    }
  }

  cout << (dist[n] == LLONG_MAX ? -1 : dist[n]) << "\n";

  return 0;
}
