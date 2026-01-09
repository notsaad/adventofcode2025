#include <bits/stdc++.h>

int main()
{
    int ans = 0;

    std::vector<std::vector<int>> grid;
    std::string line;
    while (getline(std::cin, line))
    {
        std::vector<int> row;
        for (size_t i = 0; i < line.size(); ++i)
        {
            if (line[i] == '.')
            {
                row.push_back(0);
            }
            else
            {
                row.push_back(1);
            }
        }
        grid.push_back(row);
    }

    const size_t ROWS = grid.size();
    const size_t COLS = grid[0].size();
    const std::vector<std::pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

    auto valid = [&grid, ROWS, COLS](int r, int c)
    {
        if (r >= 0 && c >= 0 && r < ROWS && c < COLS && grid[r][c] == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };

    for (size_t r = 0; r < ROWS; ++r)
    {
        for (size_t c = 0; c < COLS; ++c)
        {
            if (grid[r][c] == 1)
            {
                int n = 0;
                for (auto dir : directions)
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

    std::cout << ans << "\n";
}