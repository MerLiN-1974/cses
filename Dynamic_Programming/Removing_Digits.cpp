#include <algorithm>
#include <iostream>

using namespace std;

int main() {

  int n;
  cin >> n;
  int steps{};

  while (n) {
    int temp = n;
    int minm = n;

    while (temp) {
      minm = min(minm, n - temp % 10);
      temp /= 10;
    }
    n = minm;
    steps++;
  }

  cout << steps << "\n";
  return 0;
}
