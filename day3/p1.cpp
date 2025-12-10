#include <bits/stdc++.h>

int main() {
    int ans = 0;
    std::string line;
    while (getline(std::cin, line)) {
        int currMax = 0;
        for (int i = 0; i < line.size(); ++i){
            for (int j = i+1; j < line.size(); ++j) {
                int val = (line[i] - '0') * 10 + (line[j] - '0');
                if (val > currMax) {
                    currMax = val;
                }
            }
        }
        ans += currMax;
    }
    std::cout << ans << "\n";
}