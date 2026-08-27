#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class DSU {
private:
  vector<int> parent;
  vector<int> size;
  int num_sets;
  int max_size;

public:
  DSU(int n) {
    parent.resize(n + 1);
    num_sets = n;
    size.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
    max_size = 1;
  }

  int get_num_comps() { return num_sets; }
  int largest_comp_size() { return max_size; }

  int get_parent(int a) {
    if (parent[a] == a)
      return a;
    return parent[a] = get_parent(parent[a]);
  }

  int get_size(int a) { return size[get_parent(a)]; }

  void set_union(int a, int b) {
    if (get_parent(a) == get_parent(b))
      return;
    num_sets--;

    if (size[a] >= size[b]) {
      size[get_parent(a)] += get_size(b);
      parent[get_parent(b)] = get_parent(a);
    } else {
      size[get_parent(b)] += get_size(a);
      parent[get_parent(a)] = get_parent(b);
    }

    max_size = max(max_size, max(get_size(a), get_size(b)));
  }
};

int main() {

  int n, m;
  cin >> n >> m;

  DSU dsu(n);

  for (int _ = 0; _ < m; _++) {
    int a, b;
    cin >> a >> b;

    dsu.set_union(a, b);
    cout << dsu.get_num_comps() << " " << dsu.largest_comp_size() << "\n";
  }

  return 0;
}
