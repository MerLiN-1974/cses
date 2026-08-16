#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> Alist(n + 1, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    Alist[u].push_back(v);
    Alist[v].push_back(u);
  }

  vector<int> parent(n + 1, -1);

  queue<int> q{};
  q.push(1);
  parent[1] = 0;
  bool found = false;

  while (not q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : Alist[u]) {
      if (parent[v] != -1) {
        parent[v] = u;
        q.push(v);

        if (v == n) {
          found = true;
          break;
        }
      }
    }
  }

  if (not found) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vector<int> path{};
  int v = n;
  while (v != 0) {
    path.push_back(v);
    v = parent[v];
  }

  cout << path.size() << "\n";
  reverse(path.begin(), path.end());

  for (auto u : path) {
    cout << u << " ";
  }
  cout << "\n";

  return 0;
}
