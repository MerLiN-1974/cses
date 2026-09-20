#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void dfs1(int u, const vector<vector<int>> &Alist, vector<bool> &visited) {
  visited[u] = true;
  for (auto &v : Alist[u]) {
    if (not visited[v]) {
      dfs1(v, Alist, visited);
    }
  }
}

int path_len(int u, int n, const vector<vector<int>> &Alist, vector<int> &child,
             vector<int> &len) {
  if (u == n)
    return 1;
  if (len[u] != 0)
    return len[u];

  int ans = 0;
  for (auto &v : Alist[u]) {
    int sub_len = path_len(v, n, Alist, child, len);
    int temp_len = 0;
    if (sub_len != 0) {
      temp_len = sub_len + 1;
    }
    if (temp_len > ans) {
      ans = temp_len;
      child[u] = v;
    }
  }
  return len[u] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> Alist(n + 1);
  for (int _ = 0; _ < m; _++) {
    int a, b;
    cin >> a >> b;
    Alist[a].push_back(b);
  }
  vector<bool> visited(n + 1, false);
  dfs1(1, Alist, visited);

  if (not visited[n]) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  vector<int> child(n + 1, -1);
  vector<int> len(n + 1, 0);

  len[1] = path_len(1, n, Alist, child, len);

  cout << len[1];
  cout << "\n";

  int curr = 1;
  child[n] = 0;
  while (curr) {
    cout << curr << " ";
    curr = child[curr];
  }
  cout << "\n";

  return 0;
}
