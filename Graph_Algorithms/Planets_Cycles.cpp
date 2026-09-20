#include <iostream>
#include <vector>

using namespace std;


int main() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vector<int> t(n + 1, 0);
  vector<bool> visited(n + 1, false);

  for (int i = 1; i <= n; i++) {
    if (visited[i])
      continue;
    visited[i] = true;
    dfs(i, )
  }

  return 0;
}
