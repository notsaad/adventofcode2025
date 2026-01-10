#include <bits/stdc++.h>

int main() {
  int ans = 0;

  std::vector<std::vector<int>> grid;
  std::string line;
  while (getline(std::cin, line)) {
    std::vector<int> row;
    for (char c : line) {
      row.push_back(c == '.' ? 0 : 1);
    }
    grid.push_back(row);
  }

  const int ROWS = grid.size();
  const int COLS = grid[0].size();
  const std::vector<std::pair<int, int>> directions{
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

  auto valid = [&grid, ROWS, COLS](int r, int c) {
    return r >= 0 && c >= 0 && r < ROWS && c < COLS && grid[r][c] == 1;
  };

  std::vector<std::vector<int>> new_grid;

  for (int r = 0; r < ROWS; ++r) {
    std::vector<int> row;
    for (int c = 0; c < COLS; ++c) {
      if (grid[r][c] == 1) {
        int n = 0;
        for (const auto &dir : directions) {
          int newR = r + dir.first;
          int newC = c + dir.second;

          n += valid(newR, newC);
        }
        row.push_back(n);
      } else {
        row.push_back(-1);
      }
    }
    new_grid.push_back(row);
  }

  std::queue<std::pair<int, int>> q;

  // now we bfs the grid
  for (int r = 0; r < ROWS; ++r) {
    for (int c = 0; c < COLS; ++c) {
      if (new_grid[r][c] > -1 && new_grid[r][c] < 4) {
        q.push({r, c});
      }
    }
  }

  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    ans++;

    q.pop();

    for (const auto &dir : directions) {
      int newR = r + dir.first;
      int newC = c + dir.second;

      if (valid(newR, newC) && new_grid[newR][newC] >= 4) {
        new_grid[newR][newC]--;
        if (new_grid[newR][newC] < 4) {
            q.push({newR, newC});
        }
      }

    }

  }

  std::cout << ans << '\n';
}