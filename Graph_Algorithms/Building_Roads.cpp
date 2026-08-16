#include <iostream>
#include <vector>

using namespace std;

void dfs(int s, const vector<vector<int>> &Alist, vector<bool> &visited) {
  for (auto &v : Alist[s]) {
    if (not visited[v]) {
      visited[v] = true;
      dfs(v, Alist, visited);
    }
  }
}

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

  vector<bool> visited(n + 1, false);
  vector<int> components{};
  for (int v = 1; v <= n; v++) {
    if (not visited[v]) {
      visited[v] = true;
      dfs(v, Alist, visited);
      components.push_back(v);
    }
  }

  cout << components.size() - 1 << "\n";

  for (int i = 1; i < (int)components.size(); i++) {
    cout << components[i - 1] << " " << components[i] << "\n";
  }

  return 0;
}
