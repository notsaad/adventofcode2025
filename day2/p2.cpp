#include <bits/stdc++.h>

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
        bool valid = true;
        for (int i = 1; i <= s.size() / 2; ++i){
            std::string sub_s = s.substr(0, i);
            if (s.size() % sub_s.size() == 0) {
                valid = true;
                int j = 0;
                while (j + sub_s.size() <= s.size() && valid){
                    if (s.substr(j, sub_s.size()) != sub_s){
                        valid = false;
                    }
                    j += sub_s.size();
                }
                if (valid) {
                    return true;
                }
            }
        }
        return false;
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


