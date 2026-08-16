#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

const int dir[5] = {-1, 0, 1, 0, -1};
// int mat[1000][1000] = {{0}};
int n, m;

// void dfs(int r, int c, vector<vector<char>> &mat) {
//   mat[r][c] = '#';
//
//   for (int d = 0; d < 4; d++) {
//     int nr = r + dir[d];
//     int nc = c + dir[d + 1];
//
//     if (nr < 0 || nc < 0 || nr >= n || nc >= m || mat[nr][nc] == '#')
//       continue;
//
//     dfs(nr, nc, mat);
//   }
// }

void dfs(int x, int y, vector<vector<char>> &mat) {
  stack<pair<int, int>, vector<pair<int, int>>> stack{};
  stack.push(make_pair(x, y));

  while (not stack.empty()) {
    auto [r, c] = stack.top();
    stack.pop();

    if (mat[r][c] == '#')
      continue;
    mat[r][c] = '#';

    for (int d = 0; d < 4; d++) {
      int nr = r + dir[d];
      int nc = c + dir[d + 1];

      if (nr < 0 || nc < 0 || nr >= n || nc >= m || mat[nr][nc] == '#')
        continue;
      stack.push(make_pair(nr, nc));
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  vector<vector<char>> mat(n, vector<char>(m));

  for (auto &i : mat) {
    for (auto &j : i)
      cin >> j;
  }

  int room_cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] != '#') {
        room_cnt++;
        dfs(i, j, mat);
      }
    }
  }

  cout << room_cnt << "\n";

  return 0;
}
