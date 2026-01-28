#include <bits/stdc++.h>

struct Point {
  long long x;
  long long y;
};

int main() {
  std::ifstream inputFile("input.txt");
  long long ans = 0;
  std::vector<Point> points;
  std::string line;

  while (getline(inputFile, line)) {
    std::stringstream ss(line);
    Point v;
    char comma;

    ss >> v.x >> comma >> v.y;
    points.push_back(v);
  }

  for (size_t i=0; i<points.size(); ++i) {
    for (size_t j=i+1; j<points.size(); ++j) {
      Point a = points[i];
      Point b = points[j];

      long long area = ((std::abs(a.x - b.x) +1) * (std::abs(a.y - b.y) +1));

      ans = std::max(ans, area);
    }
  }


  std::cout << ans << '\n';
}