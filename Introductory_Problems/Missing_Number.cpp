#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  ll sum = ((ll)n * (n + 1)) / 2;

  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    sum -= x;
  }

  cout << sum << "\n";

  return 0;
}
