#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <iterator>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<ll, int>>> Alist(n + 1);
  for (int _ = 0; _ < m; _++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    Alist[a].push_back({c, b});
  }

  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>>
      pq{};
  vector<vector<ll>> dist(n + 1, vector<ll>(2, LLONG_MAX));
  dist[1][0] = 0, dist[1][1] = 0;

  pq.push({0, 1, 0});
  pq.push({0, 1, 1});

  while (not pq.empty()) {
    auto [c, u, disc] = pq.top();
    pq.pop();

    if (c > dist[u][disc])
      continue;

    for (auto [w, v] : Alist[u]) {
      if (disc) {
        if (c + w < dist[v][1]) {
          dist[v][1] = c + w;
          pq.push({dist[v][1], v, 1});
        }
      } else {
        if (c + w / 2 < dist[v][1]) {
          dist[v][1] = c + w / 2;
          pq.push({dist[v][1], v, 1});
        }
        if (c + w < dist[v][0]) {
          dist[v][0] = c + w;
          pq.push({dist[v][0], v, 0});
        }
      }
    }
  }

  cout << dist[n][1] << "\n";
  return 0;
}
