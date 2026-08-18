#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> Alist;
vector<int> parent;
int start_cycle = -1;
int end_cycle = -1;

bool dfs(int u) {
  for (int v : Alist[u]) {
    if (v == parent[u])
      continue;
    if (parent[v] == -1) {
      parent[v] = u;
      if (dfs(v))
        return true;
    } else {
      start_cycle = v;
      end_cycle = u;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  Alist.resize(n + 1);
  parent.resize(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    Alist[u].push_back(v);
    Alist[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (parent[i] == -1) {
      parent[i] = 0;
      if (dfs(i))
        break;
    }
  }

  if (start_cycle == -1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  vector<int> path{};
  path.reserve(n);
  for (int curr = end_cycle; curr != start_cycle; curr = parent[curr]) {
    path.push_back(curr);
  }
  path.push_back(start_cycle);
  reverse(path.begin(), path.end());
  path.push_back(start_cycle);

  cout << path.size() << "\n";
  for (int i : path) {
    cout << i << " ";
  }
  cout << "\n";

  return 0;
}
