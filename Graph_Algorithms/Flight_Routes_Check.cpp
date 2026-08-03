#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, const vector<vector<int>> &Alist, vector<bool> &visited) {
  if (visited[u])
    return;

  visited[u] = true;
  for (const auto &v : Alist[u]) {
    if (not visited[v]) {
      dfs(v, Alist, visited);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> Alist1(n + 1);
  vector<vector<int>> Alist2(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    Alist1[u].push_back(v);
    Alist2[v].push_back(u);
  }

  vector<bool> visited(n + 1, false);
  dfs(1, Alist1, visited);

  for (int i = 1; i <= n; i++) {
    if (not visited[i]) {
      cout << "NO\n";
      cout << 1 << " " << i << "\n";
      return 0;
    }
    visited[i] = false;
  }

  dfs(1, Alist2, visited);
  for (int i = 1; i <= n; i++) {
    if (not visited[i]) {
      cout << "NO\n";
      cout << i << " " << 1 << "\n";
      return 0;
    }
    visited[i] = false;
  }

  cout << "YES\n";

  return 0;
}
