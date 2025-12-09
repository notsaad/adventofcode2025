#include <bits/stdc++.h>

// Parses a single comma-separated line of "a-b" pairs into a vector.
int main()
{
    long long ans = 0;
    std::string line;
    if (!std::getline(std::cin, line))
    {
        return 0;
    }

    std::vector<std::pair<long long, long long>> ranges;
    std::stringstream line_stream(line);
    std::string token;

    auto trim_spaces = [](std::string &s)
    {
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char ch)
                               { return std::isspace(ch); }),
                s.end());
    };

    auto invalid = [](std::string const &s)
    {
        return s.size() % 2 == 0 &&
               s.substr(0, s.size() / 2) ==
                   s.substr(s.size() / 2);
    };

    while (std::getline(line_stream, token, ','))
    {
        trim_spaces(token);
        if (token.empty())
        {
            continue;
        }

        std::stringstream pair_stream(token);
        std::string first, second;
        if (std::getline(pair_stream, first, '-') && std::getline(pair_stream, second))
        {
            trim_spaces(first);
            trim_spaces(second);
            ranges.emplace_back(std::stoll(first), std::stoll(second));
        }
    }

    for (auto p : ranges)
    {
        for (long long i = p.first; i <= p.second; ++i){
            if (invalid(std::to_string(i))) {
                ans += i;
            }
        }
    }

    std::cout << ans << "\n";
}

