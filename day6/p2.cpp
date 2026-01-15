#include <bits/stdc++.h>

int main() {
  std::ifstream inputFile("input.txt");
  long long ans = 0;
  std::string line;
  std::vector<std::vector<char>> grid;

  while (getline(inputFile, line)) {
    std::vector<char> row;
    for (char c : line) {
      row.push_back(c);
    }
    grid.push_back(row);
  }

  const int ROWS = grid.size();
  const int COLS = grid[0].size();
  std::unordered_set<char> operands = {'+', '*'};

  // loop through the last row of the grid for operands
  for (size_t c = 0; c < COLS; ++c) {
    char letter = grid.back()[c];
    std::vector<long long> nums;
    std::string num;
    if (operands.count(letter)) {
      do {
        num = "";
        size_t r = 0;
        while (r < ROWS - 1) {
          if (std::isdigit(grid[r][c])) {
            num += grid[r][c];
          }
          ++r;
        }
        if (num != "") {
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