#include <bits/stdc++.h>

int main() {
  std::ifstream inputFile("input.txt");
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
    long long x, y;
    std::sscanf(line.c_str(), "%lld-%lld", &x, &y);
    ranges.push_back({x, y});
  }

  // sort and merge the intervals
  std::sort(ranges.begin(), ranges.end());

  std::vector<std::pair<long long, long long>> merged_ranges = {ranges[0]};

  for (size_t i = 1; i < ranges.size(); ++i) {
    if (ranges[i].first <= merged_ranges.back().second) {
      merged_ranges.back().first = std::min(ranges[i].first, merged_ranges.back().first);
      merged_ranges.back().second = std::max(ranges[i].second, merged_ranges.back().second);
    } else {
      merged_ranges.push_back(ranges[i]);
    }
  }

  // iterate over the intervals and add them the length of the range to ans
  for (const auto& [start, end] : merged_ranges) {
    ans += (end - start + 1);
  }

  std::cout << ans << '\n';
}