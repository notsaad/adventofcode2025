#include <bits/stdc++.h>

int main() {
  std::ifstream inputFile("input.txt");
  if (!inputFile) { return 1; }
  long long ans = 0;
  std::string line;
  std::vector<std::vector<char>> grid;

  while (getline(inputFile, line)) {
    grid.emplace_back(line.begin(), line.end());
  }

  if (grid.empty()) { return 1; }

  const size_t ROWS = grid.size();
  const size_t COLS = grid[0].size();

  // loop through the last row of the grid for operands
  for (size_t c = 0; c < COLS; ++c) {
    char letter = grid.back()[c];
    if (letter == '+' || letter == '*') {
      std::vector<long long> nums;
      std::string num;
      do {
        num = "";
        size_t r = 0;
        while (r + 1 < ROWS) {
          if (std::isdigit(grid[r][c])) {
            num += grid[r][c];
          }
          ++r;
        }
        if (!num.empty()) {
          nums.push_back(std::stoll(num));
          ++c;
        }
      } while (num != "" && c < COLS);
      long long count = (letter == '*' ? 1 : 0);
      for (long long n : nums) {
        if (letter == '*') {
          count *= n;
        } else {
          count += n;
        }
      }
      ans += count;
    }
  }

  std::cout << ans << '\n';
}