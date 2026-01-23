#include <bits/stdc++.h>

class UnionFind {
private:
  std::vector<int> parents;
  std::vector<int> rank;

public:

  UnionFind(int n) {
    parents.resize(n);
    rank.resize(n);

    for (size_t i=0; i<parents.size(); ++i) {
      parents[i] = i;
    }

  }

  int find(int x) {
    if (parents[x] != x) {
      parents[x] = find(parents[x]);
    }
    return parents[x];
  }

  bool merge(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
      return false;
    }

    if (rank[rootX] < rank[rootY]){
      parents[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
      parents[rootY] = rootX;
    } else {
      parents[rootY] = rootX;
      rank[rootX]++;
    }

    return true;
  }

  std::vector<int> getComponentSizes() {
    std::map<int, int> sizeMap;

    for (size_t i = 0; i < parents.size(); ++i) {
      int root = find(i);
      sizeMap[root]++;
    }

    std::vector<int> sizes;
    for (auto [root, size] : sizeMap) {
      sizes.push_back(size);
    }

    std::sort(sizes.begin(), sizes.end(), std::greater<int>());
    return sizes;
  }
};

struct Vector {
  long long x;
  long long y;
  long long z;
};

int main() {
  std::ifstream inputFile("input.txt");
  long long ans = 0;
  std::string line;
  std::vector<Vector> data;

  while (getline(inputFile, line)) {
    std::stringstream ss(line);
    Vector v;
    char comma;

    ss >> v.x >> comma >> v.y >> comma >> v.z;
    data.push_back(v);
  }

  UnionFind uf(data.size());
  int components = data.size();

  std::priority_queue<std::pair<long long, std::pair<size_t, size_t>>,
                      std::vector<std::pair<long long, std::pair<size_t, size_t>>>,
                      std::greater<>>
      edges;

  auto distance = [&](Vector v1, Vector v2) {
    long long d1 = (v2.x - v1.x) * (v2.x - v1.x);
    long long d2 = (v2.y - v1.y) * (v2.y - v1.y);
    long long d3 = (v2.z - v1.z) * (v2.z - v1.z);
    return d1 + d2 + d3;
  };

  for (size_t i = 0; i < data.size(); ++i) {
    for (size_t j = i + 1; j < data.size(); ++j) {
      long long dist = distance(data[i], data[j]);
      edges.push({dist, {i, j}});
    }
  }

  while (components != 1) {
    auto [dist, indices] = edges.top();
    auto [x, y] = indices;
    edges.pop();

    if (uf.merge(x, y)) {
      components--;
      if (components == 1) {
        ans = data[x].x * data[y].x;
      }
    }
  }

  std::cout << ans << '\n';
}