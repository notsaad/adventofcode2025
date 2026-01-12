#include <bits/stdc++.h>

int main() {
  std::ifstream inputFile("input.txt");
  bool all_ranges_seen = false;
  long long ans = 0;
  std::string line;
  std::vector<std::pair<long long, long long>> ranges;

  auto in_range = [&ranges](long long n) {
    for (const auto& [lo, hi] : ranges) {
        if (n >= lo && n <= hi) return true;
    }
    return false;
  };


  while (getline(inputFile, line)) {
    if (line == "") {
      all_ranges_seen = true;
      continue;
    }

    if (all_ranges_seen) {
      long long n = std::stoll(line);
      if (in_range(n)) {
        ans++;
      }
    } else {
      long long x, y;
      std::sscanf(line.c_str(), "%lld-%lld", &x, &y);
      ranges.push_back({x, y});
    }
  }

  std::cout << ans << '\n';
}