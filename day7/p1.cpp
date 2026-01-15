#include <bits/stdc++.h>

int main() {
  std::ifstream inputFile("input.txt");
  long long ans = 0;
  std::string line;
  std::vector<std::vector<char>> grid;

  while (getline(inputFile, line)) {
    grid.emplace_back(line.begin(), line.end());
  }

  // seems like a simple recursion problem

  if (grid.empty()) { return 1; }
  const int COLS = grid[0].size();
  const int ROWS = grid.size();

  std::function<void(int, int)> recurse = [&](int row, int col){
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] != '.') { return; }
    while (row < ROWS && grid[row][col] == '.') {
      grid[row][col] = '|';
      ++row;
    }

    if (row < ROWS && grid[row][col] == '^') {
      ++ans;
      recurse(row, col +1);
      recurse(row, col -1);
    }

  };

  for (int c=0; c<COLS; ++c) {
    if (grid[0][c] == 'S') {
      recurse(1, c);
    }
  }


  //print the grid
  // for (const auto& row : grid) {
  //   for (char c : row) {
  //     std::cout << c;
  //   }
  //   std::cout << '\n';
  // }

  std::cout << ans << '\n';
}