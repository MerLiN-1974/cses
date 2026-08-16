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

  vector<int> color(n + 1, -1);

  for (int i = 1; i <= n; i++) {
    if (color[i] != -1)
      continue;
    queue<int> q{};
    q.push(i);
    color[i] = 1;

    while (not q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : Alist[u]) {
        if (color[v] == -1) {
          color[v] = 3 - color[u];
          q.push(v);
        } else if (color[v] == color[u]) {
          cout << "IMPOSSIBLE\n";
          return 0;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << color[i] << " ";
  }
  cout << "\n";

  return 0;
}
