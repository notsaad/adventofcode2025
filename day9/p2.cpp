#include <bits/stdc++.h>
struct Point {
  long long x;
  long long y;
};

int main() {
  std::ifstream inputFile("test.txt");
  long long ans = 0;
  std::vector<Point> points;
  std::string line;
  std::vector<std::pair<Point, Point>> edges;
  
  while (getline(inputFile, line)) {
    std::stringstream ss(line);
    Point v;
    char comma;
    ss >> v.x >> comma >> v.y;
    points.push_back(v);
  }
  
  for (size_t i = 0; i < points.size() - 1; ++i) {
    edges.push_back({points[i], points[i + 1]});
  }
  edges.push_back({points.back(), points.front()});

  auto is_inside = [&](Point p) {
    int collisions = 0;
    for (const auto &e : edges) {
      if (e.first.x == e.second.x && e.first.x > p.x) {
        long long minY = std::min(e.first.y, e.second.y);
        long long maxY = std::max(e.first.y, e.second.y);
        if (p.y > minY && p.y < maxY) {
          collisions++;
        }
      }
    }
    return collisions % 2 == 1;
  };

  // Check if a polygon edge cuts through the rectangle's interior
  auto edge_cuts_rectangle = [](const std::pair<Point, Point>& edge, 
                                 long long minX, long long maxX, 
                                 long long minY, long long maxY) {
    long long ex1 = edge.first.x, ey1 = edge.first.y;
    long long ex2 = edge.second.x, ey2 = edge.second.y;
    
    if (ex1 == ex2) { // vertical edge
      // Check if it cuts through horizontally (strictly inside x range)
      if (ex1 > minX && ex1 < maxX) {
        long long eMinY = std::min(ey1, ey2);
        long long eMaxY = std::max(ey1, ey2);
        // Check if there's vertical overlap
        if (eMinY < maxY && eMaxY > minY) {
          return true;
        }
      }
    } else { // horizontal edge (ey1 == ey2)
      // Check if it cuts through vertically (strictly inside y range)
      if (ey1 > minY && ey1 < maxY) {
        long long eMinX = std::min(ex1, ex2);
        long long eMaxX = std::max(ex1, ex2);
        // Check if there's horizontal overlap
        if (eMinX < maxX && eMaxX > minX) {
          return true;
        }
      }
    }
    return false;
  };

  for (size_t i = 0; i < points.size(); ++i) {
    for (size_t j = i + 1; j < points.size(); ++j) {
      Point a = {points[i].x, points[j].y};
      Point b = {points[j].x, points[i].y};
      
      if (!is_inside(a) || !is_inside(b)) continue;
      
      long long minX = std::min(points[i].x, points[j].x);
      long long maxX = std::max(points[i].x, points[j].x);
      long long minY = std::min(points[i].y, points[j].y);
      long long maxY = std::max(points[i].y, points[j].y);
      
      // had to get ai to help me with this part, the edge cutting logic was tricky to comprehend
      bool valid = true;
      for (const auto& edge : edges) {
        if (edge_cuts_rectangle(edge, minX, maxX, minY, maxY)) {
          valid = false;
          break;
        }
      }
      
      if (valid) {
        long long area = (maxX - minX + 1) * (maxY - minY + 1);
        ans = std::max(ans, area);
      }
    }
  }
  
  std::cout << ans << '\n';
}