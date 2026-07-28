#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int M = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char ch;
      cin >> ch;
      if (ch == '*')
        continue;
      if (i == 0 && j == 0) {
        grid[i][j] = 1;
        continue;
      }

      if (i > 0)
        grid[i][j] = grid[i - 1][j];
      if (j > 0)
        grid[i][j] = (grid[i][j] + grid[i][j - 1]) % M;
    }
  }

  cout << grid.back().back();

  return 0;
}
