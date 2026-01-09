#include <bits/stdc++.h>

int main()
{
    int ans = 0;

    std::vector<std::vector<int>> grid;
    std::string line;
    while (getline(std::cin, line))
    {
        std::vector<int> row;
        for (char c : line) {
            row.push_back(c == '.' ? 0 : 1);
        }
        grid.push_back(row);
    }

    const int ROWS = grid.size();
    const int COLS = grid[0].size();
    const std::vector<std::pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

    auto valid = [&grid, ROWS, COLS](int r, int c)
    {
        return r >= 0 && c >= 0 && r < ROWS && c < COLS && grid[r][c] == 1;
    };

    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            if (grid[r][c] == 1)
            {
                int n = 0;
                for (const auto& dir : directions)
                {
                    int newR = r + dir.first;
                    int newC = c + dir.second;

                    n += valid(newR, newC);
                }
                if (n < 4)
                {
                    ans++;
                }
            }
        }
    }

    std::cout << ans << '\n';
}