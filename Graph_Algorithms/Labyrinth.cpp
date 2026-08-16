#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int dir[5] = {-1, 0, 1, 0, -1};
enum DIR { U, R, D, L };

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> n >> m;

  pair<int, int> A, B;

  vector<vector<char>> mat(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == 'A')
        A = make_pair(i, j);
      if (mat[i][j] == 'B')
        B = make_pair(i, j);
    }
  }

  queue<pair<int, int>, deque<pair<int, int>>> q{};
  q.push(A);

  while (not q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (x == B.first and y == B.second) {
      break;
    }

    for (int d = 0; d < 4; d++) {
      int nr = x + dir[d];
      int nc = y + dir[d + 1];

      if (nr < 0 || nc < 0 || nr >= n || nc >= m)
        continue;

      if (mat[nr][nc] != 'B' && mat[nr][nc] != '.')
        continue;

      switch (d) {
      case U:
        mat[nr][nc] = 'U';
        break;
      case R:
        mat[nr][nc] = 'R';
        break;
      case D:
        mat[nr][nc] = 'D';
        break;
      case L:
        mat[nr][nc] = 'L';
        break;
      }

      q.push(make_pair(nr, nc));
    }
  }

  int x = B.first, y = B.second;
  if (mat[x][y] == 'B') {
    cout << "NO\n";
    return 0;
  }

  string path{};
  while (x != A.first or y != A.second) {
    path.push_back(mat[x][y]);
    switch (mat[x][y]) {
    case 'U':
      x += 1;
      break;
    case 'D':
      x -= 1;
      break;
    case 'R':
      y -= 1;
      break;
    case 'L':
      y += 1;
      break;
    }
  }

  reverse(path.begin(), path.end());

  cout << "YES\n" << path.size() << "\n" << path << "\n";

  return 0;
}
